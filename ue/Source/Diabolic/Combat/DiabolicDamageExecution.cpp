#include "Combat/DiabolicDamageExecution.h"
#include "Combat/DiabolicAttributeSet.h"

struct FDiabolicDamageStatics
{
    FGameplayEffectAttributeCaptureDefinition DamageDef;
    FGameplayEffectAttributeCaptureDefinition CritChanceDef;
    FGameplayEffectAttributeCaptureDefinition CritMultDef;
    FGameplayEffectAttributeCaptureDefinition ArmorDef;

    FDiabolicDamageStatics()
    {
        DamageDef = FGameplayEffectAttributeCaptureDefinition(UDiabolicAttributeSet::GetDamageAttribute(), EGameplayEffectAttributeCaptureSource::Source, false);
        CritChanceDef = FGameplayEffectAttributeCaptureDefinition(UDiabolicAttributeSet::GetCritChanceAttribute(), EGameplayEffectAttributeCaptureSource::Source, false);
        CritMultDef = FGameplayEffectAttributeCaptureDefinition(UDiabolicAttributeSet::GetCritMultiplierAttribute(), EGameplayEffectAttributeCaptureSource::Source, false);
        ArmorDef = FGameplayEffectAttributeCaptureDefinition(UDiabolicAttributeSet::GetArmorAttribute(), EGameplayEffectAttributeCaptureSource::Target, false);
    }
};

static const FDiabolicDamageStatics& DamageStatics()
{
    static FDiabolicDamageStatics Statics;
    return Statics;
}

UDiabolicDamageExecution::UDiabolicDamageExecution()
{
    RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritChanceDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritMultDef);
    RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
}

float UDiabolicDamageExecution::ComputeMitigatedDamage(
    float Raw, float Armor, float CritChance, float CritMultiplier, FRandomStream& Rng, bool& bOutCrit)
{
    bOutCrit = Rng.FRand() < FMath::Clamp(CritChance, 0.f, 1.f);
    const float Rolled = bOutCrit ? Raw * FMath::Max(CritMultiplier, 1.f) : Raw;
    const float SafeArmor = FMath::Max(Armor, 0.f);
    return FMath::Max(0.f, Rolled * (100.f / (100.f + SafeArmor)));
}

void UDiabolicDamageExecution::Execute_Implementation(
    const FGameplayEffectCustomExecutionParameters& ExecutionParams,
    FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

    float Damage = 0.f;
    float CritChance = 0.f;
    float CritMult = 1.5f;
    float Armor = 0.f;

    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DamageDef, FAggregatorEvaluateParameters(), Damage);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().CritChanceDef, FAggregatorEvaluateParameters(), CritChance);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().CritMultDef, FAggregatorEvaluateParameters(), CritMult);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorDef, FAggregatorEvaluateParameters(), Armor);

    FRandomStream Rng(Spec.GetContext().GetSourceObject() ? FMath::Rand() : FMath::Rand());
    bool bCrit = false;
    const float Mitigated = ComputeMitigatedDamage(Damage, Armor, CritChance, CritMult, Rng, bCrit);

    OutExecutionOutput.AddOutputModifier(
        FGameplayModifierEvaluatedData(UDiabolicAttributeSet::GetHealthAttribute(), EGameplayModOp::Additive, -Mitigated));
}

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "DiabolicDamageExecution.generated.h"

/**
 * Act I damage. Reads source Damage / CritChance / CritMultiplier and target Armor.
 * mitigated = raw * (100 / (100 + armor)). Crit replaces raw before mitigation.
 * Writes -mitigated into target Health via the execution output.
 */
UCLASS()
class DIABOLIC_API UDiabolicDamageExecution : public UGameplayEffectExecutionCalculation
{
    GENERATED_BODY()

public:
    UDiabolicDamageExecution();
    virtual void Execute_Implementation(
        const FGameplayEffectCustomExecutionParameters& ExecutionParams,
        FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

    static float ComputeMitigatedDamage(float Raw, float Armor, float CritChance, float CritMultiplier, FRandomStream& Rng, bool& bOutCrit);
};

#include "Combat/DiabolicAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UDiabolicAttributeSet::UDiabolicAttributeSet()
{
    InitHealth(100.f);
    InitMaxHealth(100.f);
    InitDamage(12.f);
    InitArmor(0.f);
    InitCritChance(0.05f);
    InitCritMultiplier(1.5f);
}

void UDiabolicAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME_CONDITION_NOTIFY(UDiabolicAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDiabolicAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDiabolicAttributeSet, Damage, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDiabolicAttributeSet, Armor, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDiabolicAttributeSet, CritChance, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UDiabolicAttributeSet, CritMultiplier, COND_None, REPNOTIFY_Always);
}

void UDiabolicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);
    ClampVital(Attribute, NewValue);
}

void UDiabolicAttributeSet::ClampVital(const FGameplayAttribute& Attribute, float& NewValue) const
{
    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
    }
    else if (Attribute == GetMaxHealthAttribute())
    {
        NewValue = FMath::Max(NewValue, 1.f);
    }
    else if (Attribute == GetArmorAttribute())
    {
        NewValue = FMath::Max(NewValue, 0.f);
    }
    else if (Attribute == GetCritChanceAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, 1.f);
    }
    else if (Attribute == GetCritMultiplierAttribute())
    {
        NewValue = FMath::Max(NewValue, 1.f);
    }
}

void UDiabolicAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
        if (GetHealth() <= 0.f)
        {
            AActor* Victim = GetOwningActor();
            AActor* Killer = Data.EffectSpec.GetContext().GetOriginalInstigator();
            OnDeath.Broadcast(Victim, Killer);
        }
    }
    else if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
    {
        SetHealth(FMath::Min(GetHealth(), GetMaxHealth()));
    }
}

void UDiabolicAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDiabolicAttributeSet, Health, OldValue);
}
void UDiabolicAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDiabolicAttributeSet, MaxHealth, OldValue);
}
void UDiabolicAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDiabolicAttributeSet, Damage, OldValue);
}
void UDiabolicAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDiabolicAttributeSet, Armor, OldValue);
}
void UDiabolicAttributeSet::OnRep_CritChance(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDiabolicAttributeSet, CritChance, OldValue);
}
void UDiabolicAttributeSet::OnRep_CritMultiplier(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDiabolicAttributeSet, CritMultiplier, OldValue);
}

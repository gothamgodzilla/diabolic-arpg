#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "DiabolicAttributeSet.generated.h"

#define DIABOLIC_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiabolicDeathSignature, AActor*, Victim, AActor*, Killer);

UCLASS()
class DIABOLIC_API UDiabolicAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UDiabolicAttributeSet();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital")
    FGameplayAttributeData Health;
    DIABOLIC_ATTRIBUTE_ACCESSORS(UDiabolicAttributeSet, Health)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital")
    FGameplayAttributeData MaxHealth;
    DIABOLIC_ATTRIBUTE_ACCESSORS(UDiabolicAttributeSet, MaxHealth)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Damage, Category = "Offense")
    FGameplayAttributeData Damage;
    DIABOLIC_ATTRIBUTE_ACCESSORS(UDiabolicAttributeSet, Damage)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Defense")
    FGameplayAttributeData Armor;
    DIABOLIC_ATTRIBUTE_ACCESSORS(UDiabolicAttributeSet, Armor)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritChance, Category = "Offense")
    FGameplayAttributeData CritChance;
    DIABOLIC_ATTRIBUTE_ACCESSORS(UDiabolicAttributeSet, CritChance)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritMultiplier, Category = "Offense")
    FGameplayAttributeData CritMultiplier;
    DIABOLIC_ATTRIBUTE_ACCESSORS(UDiabolicAttributeSet, CritMultiplier)

    UPROPERTY(BlueprintAssignable, Category = "Vital")
    FDiabolicDeathSignature OnDeath;

protected:
    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldValue);
    UFUNCTION()
    void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);
    UFUNCTION()
    void OnRep_Damage(const FGameplayAttributeData& OldValue);
    UFUNCTION()
    void OnRep_Armor(const FGameplayAttributeData& OldValue);
    UFUNCTION()
    void OnRep_CritChance(const FGameplayAttributeData& OldValue);
    UFUNCTION()
    void OnRep_CritMultiplier(const FGameplayAttributeData& OldValue);

    void ClampVital(const FGameplayAttribute& Attribute, float& NewValue) const;
};

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GASSample/GSPreprocessor.h"
#include "GASSample/GAS/GSAbilityComponent.h"
#include "GSAttributeSet.generated.h"

UCLASS()
class GASSAMPLE_API UGSAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UGSAttributeSet();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    MAKE_ATTRIBUTE_INIT(UGSAttributeSet)

    MAKE_ATTRIBUTE(PartDamage)
    UPROPERTY()
    FGameplayAttributeData PartDamage;

    MAKE_ATTRIBUTE(Damage)
    UPROPERTY()
    FGameplayAttributeData Damage;

    MAKE_ATTRIBUTE(Health)
    UPROPERTY(ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health;
    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& PreviousData);

    MAKE_ATTRIBUTE(HealthMax)
    UPROPERTY(ReplicatedUsing = OnRep_HealthMax)
    FGameplayAttributeData HealthMax;
    UFUNCTION()
    void OnRep_HealthMax(const FGameplayAttributeData& PreviousData);

    // Part
    MAKE_ATTRIBUTE(HeadHealth)
    UPROPERTY(ReplicatedUsing = OnRep_HeadHealth)
    FGameplayAttributeData HeadHealth;
    UFUNCTION()
    void OnRep_HeadHealth(const FGameplayAttributeData& PreviousData);

    MAKE_ATTRIBUTE(ArmHealth)
    UPROPERTY(ReplicatedUsing = OnRep_ArmHealth)
    FGameplayAttributeData ArmHealth;
    UFUNCTION()
    void OnRep_ArmHealth(const FGameplayAttributeData& PreviousData);


};
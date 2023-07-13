#include "GSAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UGSAttributeSet::UGSAttributeSet()
{

}

void UGSAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UGSAttributeSet, Health);
    DOREPLIFETIME(UGSAttributeSet, HealthMax);
    DOREPLIFETIME(UGSAttributeSet, HeadHealth);
    DOREPLIFETIME(UGSAttributeSet, ArmHealth);
}

void UGSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& Value)
{
    Super::PreAttributeChange(Attribute, Value);

    if (Attribute == GetHealthAttribute())
    {
        Value = FMath::Clamp<float>(Value, 0.f, GetHealthMax());
    }
}

void UGSAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    const auto InputDamage = GetDamage();
    SetDamage(0);

    if (Data.EvaluatedData.Attribute == GetPartDamageAttribute())
    {
        // Get part using DynamicTags
        // Data.EffectSpec.GetDynamicAssetTags()

        for (const auto& [Tag, Value] : Data.EffectSpec.SetByCallerTagMagnitudes)
        {
            if (Tag == FGameplayTag::RequestGameplayTag("Part.Arm"))
            {
                SetArmHealth(GetArmHealth() - Value);
            }
            else if (Tag == FGameplayTag::RequestGameplayTag("Part.Head"))
            {
                SetHeadHealth(GetHeadHealth() - Value);
            }
        }
    }

    if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    {
        SetHealth(GetHealth() - InputDamage);
    }
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        SetHealth(GetHealth() - InputDamage);
    }


    // Check if player should die
    // const auto TargetPlayer = Data.Target.GetOwner();
    // TargetPlayer->CheckDeath(Data);
}

MAKE_ATTRIBUTE_DEF(UGSAttributeSet, Health);
MAKE_ATTRIBUTE_DEF(UGSAttributeSet, HealthMax);
MAKE_ATTRIBUTE_DEF(UGSAttributeSet, HeadHealth);
MAKE_ATTRIBUTE_DEF(UGSAttributeSet, ArmHealth);
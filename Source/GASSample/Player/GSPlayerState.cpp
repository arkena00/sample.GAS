#include "GSPlayerState.h"

#include "GASSample/GAS/GSAbilityComponent.h"
#include "GASSample/GAS/GSAttributeSet.h"

AGSPlayerState::AGSPlayerState()
{
    NetUpdateFrequency = 100.f;
    GSAbilityComponent = CreateDefaultSubobject<UGSAbilityComponent>("GSAbilityComponent");
    GSAttributeSet = CreateDefaultSubobject<UGSAttributeSet>("GSAttributeSet");
}

UGSAbilityComponent* AGSPlayerState::GetAbilitySystemComponent() const
{
    return GSAbilityComponent;
}

UGSAttributeSet* AGSPlayerState::GetAttributeSet() const
{
    return GSAttributeSet;
}
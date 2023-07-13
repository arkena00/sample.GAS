#include "GSAbilitySystemGlobals.h"

FGSEffectContext* UGSAbilitySystemGlobals::AllocGameplayEffectContext() const
{
    return new FGSEffectContext;
}

// Add custom parameters to gameplay cues
void UGSAbilitySystemGlobals::InitGameplayCueParameters(FGameplayCueParameters& CueParameters,
    const FGameplayEffectContextHandle& EffectContext)
{
}
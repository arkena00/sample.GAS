#include "GSAbilityComponent.h"

UGSAbilityComponent::UGSAbilityComponent()
{
    SetIsReplicated(true);
    ReplicationMode = EGameplayEffectReplicationMode::Mixed;
}

void UGSAbilityComponent::AbilitySpecInputPressed(FGameplayAbilitySpec& Spec)
{
    Super::AbilitySpecInputPressed(Spec);

    // We don't support UGameplayAbility::bReplicateInputDirectly.
    // Use replicated events instead so that the WaitInputPress ability task works.
    if (Spec.IsActive())
    {
        // Invoke the InputPressed event. This is not replicated here. If someone is listening, they may replicate the InputPressed event to the server.
        InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputPressed, Spec.Handle, Spec.ActivationInfo.GetActivationPredictionKey());
    }
}

void UGSAbilityComponent::ApplyPartEffect(TSubclassOf<UGameplayEffect> EffectClass, FGameplayTag PartTag, float Value)
{
    auto SpecHandle = MakeOutgoingSpec(EffectClass, 1, MakeEffectContext());

    // Pass part using DynamicTags
    // SpecHandle.Data->AppendDynamicAssetTags()

    SpecHandle.Data->SetSetByCallerMagnitude(PartTag, Value);
    ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
}
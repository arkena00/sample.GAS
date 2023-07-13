#include "GSAvatar.h"

#include "EnhancedInputSubsystems.h"
#include "GSPlayerState.h"
#include "GASSample/GAS/GSAttributeSet.h"

AGSAvatar::AGSAvatar()
{

}

void AGSAvatar::InitializeAbilities()
{
    GSAbilityComponent->ClearAllAbilities();
    GSAbilityComponent->GiveAbility(FGameplayAbilitySpec(Ability));
}

void AGSAvatar::InitializeAttributes()
{
    const auto AttributeSet = Cast<AGSPlayerState>(GetPlayerState())->GetAttributeSet();
    AttributeSet->InitHealthMax(100);
    AttributeSet->InitHealth(50);
    AttributeSet->InitHeadHealth(100);
    AttributeSet->InitArmHealth(100);
}

void AGSAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGSAvatar::PawnClientRestart()
{
    Super::PawnClientRestart();

    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(InputMappingContext, 0);
        }
    }
}

void AGSAvatar::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    if (!GSAbilityComponent.IsValid())
    {
        GSAbilityComponent = GetPlayerStateChecked<AGSPlayerState>()->GetAbilitySystemComponent();
        GSAbilityComponent->InitAbilityActorInfo(GetPlayerState(), this);
    }

    InitializeAttributes();
    InitializeAbilities();
}
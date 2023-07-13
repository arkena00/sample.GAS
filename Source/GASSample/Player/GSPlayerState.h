#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "GASSample/GAS/GSAttributeSet.h"
#include "GSPlayerState.generated.h"

class UGSAbilityComponent;

UCLASS()
class GASSAMPLE_API AGSPlayerState : public APlayerState, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AGSPlayerState();

    UFUNCTION(BlueprintCallable, Category = "GASSample")
    virtual UGSAbilityComponent* GetAbilitySystemComponent() const override;

    UFUNCTION(BlueprintCallable, Category = "GASSample")
    UGSAttributeSet* GetAttributeSet() const;

private:
    UPROPERTY()
    TObjectPtr<UGSAbilityComponent> GSAbilityComponent;
    UPROPERTY()
    TObjectPtr<UGSAttributeSet> GSAttributeSet;
};
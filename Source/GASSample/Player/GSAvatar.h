#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "GSAvatar.generated.h"

class UGameplayAbility;
class UGSAbilityComponent;
UCLASS()
class GASSAMPLE_API AGSAvatar : public ACharacter
{
    GENERATED_BODY()

public:
    AGSAvatar();

    UFUNCTION(BlueprintCallable, Category = "GASSample")
    void InitializeAbilities();
    UFUNCTION(BlueprintCallable, Category = "GASSample")
    void InitializeAttributes();

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "GASSample")
    TSubclassOf<UGameplayAbility> Ability;

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void PawnClientRestart() override;
    virtual void PossessedBy(AController* NewController) override;

private:
    TObjectPtr<UInputMappingContext> InputMappingContext;
    TWeakObjectPtr<UGSAbilityComponent> GSAbilityComponent;
};
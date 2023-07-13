// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GSAbilityComponent.generated.h"

UCLASS()
class GASSAMPLE_API UGSAbilityComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()

public:
    UGSAbilityComponent();

protected:
    virtual void AbilitySpecInputPressed(FGameplayAbilitySpec& Spec) override;

    UFUNCTION(BlueprintCallable, Category = "GASSample")
    void ApplyPartEffect(TSubclassOf<UGameplayEffect> EffectClass,  FGameplayTag PartTag, float Value);

private:
    // Handles to abilities that had their input pressed this frame.
    TArray<FGameplayAbilitySpecHandle> InputPressedSpecHandles;
    // Handles to abilities that had their input released this frame.
    TArray<FGameplayAbilitySpecHandle> InputReleasedSpecHandles;
    // Handles to abilities that have their input held.
    TArray<FGameplayAbilitySpecHandle> InputHeldSpecHandles;
};
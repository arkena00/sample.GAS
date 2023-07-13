#include "GSAssetManager.h"

#include "AbilitySystemGlobals.h"

void UGSAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();

    UAbilitySystemGlobals::Get().InitGlobalData();
}
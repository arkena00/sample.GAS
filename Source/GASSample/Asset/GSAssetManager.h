#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GSAssetManager.generated.h"

UCLASS()
class GASSAMPLE_API UGSAssetManager : public UAssetManager
{
    GENERATED_BODY()

protected:
    virtual void StartInitialLoading() override;
};
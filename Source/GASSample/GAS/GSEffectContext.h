#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GSEffectContext.generated.h"

USTRUCT()
struct FGSEffectContext : public FGameplayEffectContext
{
    GENERATED_BODY()

    virtual UScriptStruct* GetScriptStruct() const override
    {
        return FGSEffectContext::StaticStruct();
    }

    virtual FGSEffectContext* Duplicate() const override
    {
        FGSEffectContext* NewContext = new FGSEffectContext();
        *NewContext = *this;
        // Copy context data here
        NewContext->AddActors(Actors);

        return NewContext;
    }

    virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) override
    {
        bOutSuccess &= Super::NetSerialize(Ar, Map, bOutSuccess);

        // Data serialization
        return true;
    }

private:
    // Custom data
};

template<>
struct TStructOpsTypeTraits<FGSEffectContext> : public TStructOpsTypeTraitsBase2<FGSEffectContext>
{
    enum
    {
        WithNetSerializer = true,
        WithCopy = true
    };
};
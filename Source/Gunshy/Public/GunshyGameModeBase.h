// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GunshyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GUNSHY_API AGunshyGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

#if PLATFORM_DESKTOP || PLATFORM_WINDOWS || PLATFORM_APPLE
    virtual void BeginPlay() override;
#endif
};

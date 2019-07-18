// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GunshyGameModeBase.generated.h"

/** Forward Declarations */
class UTilePool;

/**
 * 
 */
UCLASS()
class GUNSHY_API AGunshyGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

    AGunshyGameModeBase();

    virtual void BeginPlay() override;

protected:
    UPROPERTY(EditDefaultsOnly, Category="Tile Pool")
    UTilePool* TilePool = nullptr;
    const uint8 TILES_TO_SPAWN = 144;

};

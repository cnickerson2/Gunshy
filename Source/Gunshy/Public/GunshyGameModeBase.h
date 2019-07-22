// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GunshyGameModeBase.generated.h"

/// Forward Declarations
class UTilePool;

/**
 * Defines the base game mode for the Gunshy game
 */
UCLASS()
class GUNSHY_API AGunshyGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

/// Fields and Properties
protected:
    /** The storage pool for all the Tiles */
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Tiles")
    UTilePool* TilePool = nullptr;
    /** A collection of Patterns that will be applied to the Tiles. Used to determine how many tiles to spawn */
    UPROPERTY(EditDefaultsOnly, Category = "Tiles")
    TArray<UTexture2D*> Patterns;
    /** The amount of tiles that will be created for one pattern. Must be divisible by 2. */
    UPROPERTY(EditDefaultsOnly, Category = "Tiles")
    uint8 TilesPerPattern = 4;

/// Methods
    /** Sets default values for this game modes's properties */
    AGunshyGameModeBase();
    /** Function that run after construction but also when the game starts*/
    virtual void BeginPlay() override;
    /** Create the pool of tiles */
    UFUNCTION(BlueprintCallable, Category="Tiles")
    virtual void InitializePool();


};

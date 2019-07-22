// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TilePool.generated.h"

/** Forward Declarations */
class ATile;

/**
 * Defines the pool that stores the tiles of the game. 
 * Can also be thought of as the bag where tiles are pulled from to create the pattern.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUNSHY_API UTilePool : public UActorComponent
{
	GENERATED_BODY()

private:
    /** The container for all the tile actors */
    UPROPERTY(VisibleAnywhere, Category="Tiles")
    TArray<ATile*> Pool;
    /** The Blueprint for the Tile that will be spawned in */
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<ATile> TileBP;

public:	
    /** Remove the Actor at the top of the pool stack */
    ATile* Checkout();
    /** Returns the Actor at the top of the pool stack */
    void ReturnToPool(ATile* TileToReturn);
    /** Adds the Actor at the top of the pool stack */
    void AddToPool(ATile* TileToAdd);
    /** Initialize the Pool by spawning the supplied amount of Tiles */
    void InitializePool(const TArray<UTexture2D*> Patterns, const uint8 TilesPerPattern);
    /** Spawn a Tile at the supplied position, and store it in the OutSpawnedTile */
    void SpawnTile(ATile*& OutSpawnedTile, const FVector& SpawnPosition);
    /** Spawn a Tile at 0,0,0 and store it in the OutSpawnedTile */
    void SpawnTile(ATile*& OutSpawnedTile);
    /** Shuffle the elements in the pool so that they come out in a random order */
    void ShufflePool();
    /** Returns the Names of all the items in the pool. */
    virtual FString ToString() const;
};

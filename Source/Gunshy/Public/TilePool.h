// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TilePool.generated.h"

class ATile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUNSHY_API UTilePool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTilePool();

    ATile* Checkout();
    void ReturnToPool(ATile* TileToReturn);

    void AddToPool(ATile* TileToAdd);

    void InitializePool(uint8 PoolSize);
    void SpawnTile(ATile* OutSpawnedTile, const FVector& SpawnPosition);
    void SpawnTile(ATile* OutSpawnedTile);
private:
    TArray<ATile*> Pool;

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<ATile> TileBP;
};

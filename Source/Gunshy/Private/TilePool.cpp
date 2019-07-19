// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "TilePool.h"
#include "Public/Tile.h"

// Sets default values for this component's properties
UTilePool::UTilePool()
{
	
}

/*
Remove the Actor at the top of the pool stack
*/
ATile* UTilePool::Checkout()
{
    if (Pool.Num() == 0)
    {
        return nullptr;
    }

    return Pool.Pop();
}

void UTilePool::ReturnToPool(ATile* TileToReturn)
{
    AddToPool(TileToReturn);
}

void UTilePool::AddToPool(ATile* TileToAdd)
{
    if (TileToAdd == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("[%s] Add: Added null tile."), *GetName());
        return;
    }

    Pool.Push(TileToAdd);
}

void UTilePool::InitializePool(uint8 PoolSize)
{
    if (!ensure(TileBP))
    {
        UE_LOG(LogTemp, Error, TEXT("[%s] : Tile Blueprint has not been set."), *GetName());
        return;
    }
    for(uint8 i=0; i < PoolSize; ++i)
    {
        ATile* SpawnedTile = nullptr; 
        SpawnTile(SpawnedTile, FVector(100000.0f,100000.0f,100000.0f));

        if(SpawnedTile != nullptr)
        {
            AddToPool(SpawnedTile);
        }
    }
}

void UTilePool::SpawnTile(ATile* OutSpawnedTile, const FVector& SpawnPosition)
{
    if (!ensure(TileBP))
    {
        UE_LOG(LogTemp, Error, TEXT("[%s] : Tile Blueprint has not been set."), *GetName());
        return;
    }
    OutSpawnedTile = GetWorld()->SpawnActor<ATile>(TileBP, SpawnPosition, FRotator::ZeroRotator);
    OutSpawnedTile->SetFolderPath(TEXT("/Tiles"));
}

void UTilePool::SpawnTile(ATile* OutSpawnedTile)
{
    SpawnTile(OutSpawnedTile, FVector::ZeroVector);
}


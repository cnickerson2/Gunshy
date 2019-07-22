// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "TilePool.h"
#include "Public/Tile.h"

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

void UTilePool::InitializePool(const TArray<UTexture2D*> Patterns, const uint8 TilesPerPattern)
{
    if (!ensure(TileBP))
    {
        UE_LOG(LogTemp, Error, TEXT("[%s] : Tile Blueprint has not been set."), *GetName());
        return;
    }
    for(uint8 i=0; i < (Patterns.Num() * TilesPerPattern); ++i)
    {
        ATile* SpawnedTile = nullptr; 
        SpawnTile(SpawnedTile, FVector(100000.0f,100000.0f,100000.0f));

        if(SpawnedTile != nullptr)
        {
            AddToPool(SpawnedTile);
            uint8 PatternIndex = i / TilesPerPattern;
            SpawnedTile->SetPattern(Patterns[PatternIndex]);
        }
    }
    ShufflePool();
}

void UTilePool::SpawnTile(ATile*& OutSpawnedTile, const FVector& SpawnPosition)
{
    if (!ensure(TileBP))
    {
        UE_LOG(LogTemp, Error, TEXT("[%s] : Tile Blueprint has not been set."), *GetName());
        return;
    }
    OutSpawnedTile = GetWorld()->SpawnActor<ATile>(TileBP, SpawnPosition, FRotator::ZeroRotator);
    OutSpawnedTile->SetFolderPath(TEXT("/Tiles"));
}

void UTilePool::SpawnTile(ATile*& OutSpawnedTile)
{
    SpawnTile(OutSpawnedTile, FVector::ZeroVector);
}

void UTilePool::ShufflePool()
{
    for(uint8 i = (Pool.Num()-1); i > 0; i--)
    {
        int index = (rand() % (i + 1));
        Pool.Swap(index, i);
    }
}

FString UTilePool::ToString() const
{
    FString TileString;
    for(uint8 i = 0; i < Pool.Num(); ++i)
    {
        TileString.Append(*(Pool[i]->GetName()));
        TileString.Append(TEXT(", "));
    }
    return TileString;
}


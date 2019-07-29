// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "Tile.h"

ATile* ATile::FirstSelectedTile = nullptr;

void ATile::SetPattern(UTexture2D* NewPattern)
{
    TilePattern = NewPattern;
}

void ATile::SetRemainingSurroundingTiles()
{
    FindTiles(SurroundingTiles.TilesToTheLeft, FVector::BackwardVector);    
    FindTiles(SurroundingTiles.TilesToTheRight, FVector::ForwardVector);
    FindTiles(SurroundingTiles.TilesOnTop, FVector::UpVector);    
}

void ATile::SetSelected()
{
    if (IsAbleToBeSelected())
    {
        if (ATile::FirstSelectedTile != nullptr) // Is there is already a selected tile?
        {
            if (ATile::FirstSelectedTile->TilePattern != this->TilePattern)
            {
                ATile::FirstSelectedTile->ClearSelected();
            }
            else
            {
                this->RemoveTile();
                ATile::FirstSelectedTile->RemoveTile();
            }
            ATile::FirstSelectedTile = nullptr;
        }
        else
        {
            ATile::FirstSelectedTile = this;
            AddSelectionEffect();
        }
    }
    else
    {
        if (ATile::FirstSelectedTile != nullptr)
        {
            ATile::FirstSelectedTile->ClearSelected();
        }
        ATile::FirstSelectedTile = nullptr;
    }
}

void ATile::ClearSelected()
{

}

bool ATile::FindTiles(TArray<ATile*>& OutTilesArray, FVector RaycastDirection)
{
    TArray<FHitResult> HitResults;
    FVector RaycastEndPosition = FVector(RaycastDirection.X * MAX_RAYCAST_DISTANCE.X, RaycastDirection.Y * MAX_RAYCAST_DISTANCE.Y, RaycastDirection.Z * MAX_RAYCAST_DISTANCE.Z);
    bool bWasHit = GetWorld()->SweepMultiByObjectType
    (
        HitResults,
        this->GetActorLocation(),
        this->GetActorLocation() + RaycastEndPosition,
        FQuat::Identity,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_GameTraceChannel1), // Tile object type
        FCollisionShape::MakeSphere(RAYCAST_SPHERE_RADIUS)
    );

    if(bWasHit)
    {        
        for(int i=0; i < HitResults.Num(); ++i)
        {
            OutTilesArray.AddUnique(Cast<ATile>(HitResults[i].GetActor()));
        }
    }
    return bWasHit;
}

void ATile::RemoveTile()
{
    Destroy();
}

void ATile::AddSelectionEffect()
{

}

bool ATile::IsAbleToBeSelected() const
{
    if (ATile::FirstSelectedTile == this)
    {
        return false;
    }

    if (SurroundingTiles.IsThereATileOnTop())
    {
        return false;
    }

    if (SurroundingTiles.IsThereATileToTheLeft() && SurroundingTiles.IsThereATileToTheRight())
    {
        return false;
    }

    return true;
}
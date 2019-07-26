// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "Tile.h"

ATile* ATile::FirstSelectedTile = nullptr;

void ATile::SetSelected()
{
    if(IsAbleToBeSelected())
    {        
        if(ATile::FirstSelectedTile != nullptr) // Is there is already a selected tile?
        {
            if(ATile::FirstSelectedTile->TilePattern != this->TilePattern)
            {
                this->ClearSelected();
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
}

void ATile::ClearSelected()
{

}

void ATile::AddSelectionEffect()
{

}

void ATile::RemoveTile()
{
    Destroy();
}

void ATile::SetPattern(UTexture2D* NewPattern)
{
    TilePattern = NewPattern;
}

bool ATile::IsAbleToBeSelected() const
{
    if(ATile::FirstSelectedTile == this)
    {
        return false;
    }

    if (SurroundingTiles.TileOnTop)
    {
        return false;
    }

    if (SurroundingTiles.TileToTheLeft != nullptr && SurroundingTiles.TileToTheRight != nullptr)
    {
        return false;
    }
        
    return true;
}

void ATile::SetRemainingSurroundingTiles()
{
    if (!SurroundingTiles.TileToTheLeft)
    {
        if(FindTile(SurroundingTiles.TileToTheLeft, FVector::BackwardVector))
        {
            if(SurroundingTiles.TileToTheLeft)
            {
                SurroundingTiles.TileToTheLeft->SetRightSurroundingTile(this);
            }
            else
            {
                
            }
        }
    }
    if (!SurroundingTiles.TileToTheRight)
    {
        if(FindTile(SurroundingTiles.TileToTheRight, FVector::ForwardVector))
        {
            if (SurroundingTiles.TileToTheRight)
            {
                SurroundingTiles.TileToTheRight->SetLeftSurroundingTile(this);
            }
            else
            {

            }
        }
    }
    if (!SurroundingTiles.TileOnTop)
    {
        FindTile(SurroundingTiles.TileOnTop, FVector::UpVector);
    }
}

void ATile::SetLeftSurroundingTile(ATile* LeftTile)
{
    SurroundingTiles.TileToTheLeft = LeftTile;
}

void ATile::SetRightSurroundingTile(ATile* RightTile)
{
    SurroundingTiles.TileToTheRight = RightTile;
}

bool ATile::FindTile(ATile*& OutHitTile, FVector RaycastDirection)
{
    FHitResult HitResult;
    bool bWasHit = GetWorld()->LineTraceSingleByObjectType
    (
        HitResult,
        this->GetActorLocation(),
        this->GetActorLocation() + RaycastDirection * MAX_RAYCAST_DISTANCE,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_GameTraceChannel1) // Tile object type
    );

    if(bWasHit)
    {
        OutHitTile = Cast<ATile>(HitResult.GetActor());
    }
    return bWasHit;
}


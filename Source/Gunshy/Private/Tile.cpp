// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "Tile.h"
//#include "DrawDebugHelpers.h"

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
                UE_LOG(LogTemp, Error, TEXT("[%s] SetRemainingSurroundingTiles: TileToTheLeft was null, despite FindTile returning true"), *GetName());
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
                UE_LOG(LogTemp, Error, TEXT("[%s] SetRemainingSurroundingTiles: TileToTheRight was null, despite FindTile returning true"), *GetName());
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
    FVector RaycastEndPosition = FVector(RaycastDirection.X * MAX_RAYCAST_DISTANCE.X, RaycastDirection.Y * MAX_RAYCAST_DISTANCE.Y, RaycastDirection.Z * MAX_RAYCAST_DISTANCE.Z);
    bool bWasHit = GetWorld()->SweepSingleByObjectType
    (
        HitResult,
        this->GetActorLocation(),
        this->GetActorLocation() + RaycastEndPosition,
        FQuat::Identity,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_GameTraceChannel1), // Tile object type
        FCollisionShape::MakeSphere(RAYCAST_SPHERE_RADIUS)
    );

    //DrawDebugSphere(GetWorld(), this->GetActorLocation() + RaycastEndPosition, RAYCAST_SPHERE_RADIUS, 0, bWasHit ? FColor::Green : FColor::Red, true, 100);

    if(bWasHit)
    {
        
        OutHitTile = Cast<ATile>(HitResult.GetActor());
    }
    return bWasHit;
}



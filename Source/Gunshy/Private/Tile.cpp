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


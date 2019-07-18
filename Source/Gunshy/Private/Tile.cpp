// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "Tile.h"

ATile* ATile::FirstSelectedTile = nullptr;

void ATile::SetAsSelected()
{
    if(IsAbleToBeSelected())
    {
        // TODO: Set the Tile's mesh to have a selection effect
                
        if(ATile::FirstSelectedTile != nullptr) // Check if there is another Selected tile
        {
            if(ATile::FirstSelectedTile->TilePattern != this->TilePattern)
            {
                // Invalid selection, clear both
                this->RemoveAsSelected();
                ATile::FirstSelectedTile->RemoveAsSelected();
            }
            else
            {
                this->RemoveTile();
                ATile::FirstSelectedTile->RemoveTile();
            }

            // Reset
            ATile::FirstSelectedTile = nullptr;
        }
        else // Else this is the first tile selected, set it
        {
            UE_LOG(LogTemp, Warning, TEXT("[%s] : [%d]"), *GetName(), ATile::FirstSelectedTile);
            ATile::FirstSelectedTile = this;
        }
    }
}

void ATile::RemoveAsSelected()
{

}

void ATile::RemoveTile()
{
    Destroy();
}

void ATile::SetPattern(ETilePattern NewPattern)
{
    TilePattern = NewPattern;
}

bool ATile::IsAbleToBeSelected() const
{
    if (SurroundingTiles.TileOnTop)
    {
        return false;
    }

    if (SurroundingTiles.TileToTheLeft == nullptr || SurroundingTiles.TileToTheRight == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


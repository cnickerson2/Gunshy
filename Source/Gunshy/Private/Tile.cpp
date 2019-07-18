// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "Tile.h"

void ATile::SetSelected()
{

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



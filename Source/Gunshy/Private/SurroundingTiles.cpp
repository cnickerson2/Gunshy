// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "SurroundingTiles.h"
#include "Public/Tile.h"

bool FSurroundingTiles::IsThereATileToTheLeft() const
{
    for (int i = 0; i < TilesToTheLeft.Num(); ++i)
    {
        if (IsValid(TilesToTheLeft[i]))
        {
            return true;
        }
    }
    return false;
}
bool FSurroundingTiles::IsThereATileToTheRight() const
{
    for (int i = 0; i < TilesToTheRight.Num(); ++i)
    {
        if (IsValid(TilesToTheRight[i]))
        {
            return true;
        }
    }
    return false;
}
bool FSurroundingTiles::IsThereATileOnTop() const
{
    for (int i = 0; i < TilesOnTop.Num(); ++i)
    {
        if (IsValid(TilesOnTop[i]))
        {
            return true;
        }
    }
    return false;
}

bool FSurroundingTiles::IsValid(ATile* const Obj) const
{
    if (!Obj)
    {
        return false;
    }
    if (!Obj->IsValidLowLevel())
    {
        return false;
    }
    if (Obj->IsPendingKill())
    {
        return false;
    }
    return true;
}
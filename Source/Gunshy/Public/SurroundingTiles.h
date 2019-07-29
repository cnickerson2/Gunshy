// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "SurroundingTiles.generated.h"

class ATile;

/**
 * A collection of the tiles that are surrounding this object
 */
USTRUCT(BlueprintType)
struct FSurroundingTiles
{
    GENERATED_BODY()
        /// Fields and Properties
public:
    /** An array of all the Tiles that are to the left of this Tile */
    UPROPERTY(VisibleAnywhere)
    TArray<ATile*> TilesToTheLeft;
    /** An array of all the Tiles that are to the right of this Tile */
    UPROPERTY(VisibleAnywhere)
    TArray<ATile*> TilesToTheRight;
    /** An array of all the Tiles that are above this Tile */
    UPROPERTY(VisibleAnywhere)
    TArray<ATile*> TilesOnTop;

    /// Methods
public:
    /** Returns true if there is atleast one valid tile to the left of this one */
    bool IsThereATileToTheLeft() const;
    /** Returns true if there is atleast one valid tile to the right of this one */
    bool IsThereATileToTheRight() const;
    /** Returns true if there is atleast one valid tile above this one */
    bool IsThereATileOnTop() const;

protected:
    /** Determine if the ATile that is being checked is valid */
    bool IsValid(ATile* const Obj) const;
};

// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Tile.generated.h"

/// Forward Declarations
class UTexture2D;

/**
 * A collection of the tiles that are surrounding this object
 */
USTRUCT(BlueprintType)
struct FSurroundingTiles
{
    GENERATED_BODY()
/// Fields and Properties
    ATile* TileToTheLeft = nullptr;
    ATile* TileToTheRight = nullptr;
    ATile* TileOnTop = nullptr;
};

/**
 * Defines a Tile that can be selected by the player and add to the score
 */
UCLASS()
class GUNSHY_API ATile : public AStaticMeshActor
{
    GENERATED_BODY()

/// Fields and Properties
protected:
    /** A global variable that stores the first tile that was selected so that it can be compared against the second selected */
    static ATile* FirstSelectedTile;

    /** The pattern that is displayed as a decal on the top of the tile */
    UTexture2D* TilePattern = nullptr;
    /** Reference to the tiles that are surrounding this tile */
    FSurroundingTiles SurroundingTiles;

///Methods
public:
    /** Set this tile as selected */
    void SetSelected();
    /** Clear this tile of it's selected properties */
    void ClearSelected();
    /** Add a glowing effect to let the player know which tile has been selected */
    void AddSelectionEffect();
    /** Remove the Tile from the board */
    UFUNCTION(BlueprintCallable)
    void RemoveTile();
    /** Puts the decal pattern on the Tile mesh */
    void SetPattern(UTexture2D* NewPattern);
    /** Returns true if the there is no tile on top, and no tile to at least one side */
    bool IsAbleToBeSelected() const;
};

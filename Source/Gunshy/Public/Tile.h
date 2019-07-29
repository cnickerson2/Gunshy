// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Public/SurroundingTiles.h"
#include "Tile.generated.h"

/// Forward Declarations
class UTexture2D;

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

    const FVector MAX_RAYCAST_DISTANCE = FVector(2.4f, 3.2f, 1.6f); // Dimensions of the tile allow for viewing exactly one tile away
    const float RAYCAST_SPHERE_RADIUS = 0.7f;

    /** The pattern that is displayed as a decal on the top of the tile */
    UTexture2D* TilePattern = nullptr;
    /** Reference to the tiles that are surrounding this tile */
    UPROPERTY(VisibleAnywhere, Category = "Surrounding Tiles")
    FSurroundingTiles SurroundingTiles;

///Methods
public:
    /** Puts the decal pattern on the Tile mesh */
    void SetPattern(UTexture2D* NewPattern);
    /** Set surrounding tiles that have not already been set */
    UFUNCTION(BlueprintCallable)
    void SetRemainingSurroundingTiles();
    /** Set this tile as selected */
    void SetSelected();
    /** Clear this tile of it's selected properties */
    void ClearSelected();

protected:
    /** Sends out a raycast in the supplied direction to see if there is a tile that is hit */
    bool FindTiles(TArray<ATile*>& OutTilesArray, FVector RaycastDirection);
    /** Remove the Tile from the board */
    void RemoveTile();
    /** Add a glowing effect to let the player know which tile has been selected */
    void AddSelectionEffect();
    /** Returns true if the there is no tile on top, and no tile to at least one side */
    bool IsAbleToBeSelected() const;
};
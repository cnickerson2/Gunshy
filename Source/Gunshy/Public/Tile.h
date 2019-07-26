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
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Surrounding Tiles")
    ATile* TileToTheLeft;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Surrounding Tiles")
    ATile* TileToTheRight;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Surrounding Tiles")
    ATile* TileOnTop;

    FSurroundingTiles() : TileToTheLeft(nullptr), TileToTheRight(nullptr), TileOnTop(nullptr)
    {

    }
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

    const FVector MAX_RAYCAST_DISTANCE = FVector(2.4f, 3.2f, 1.6f); // Dimensions of the tile allow for viewing exactly one tile away
    const float RAYCAST_SPHERE_RADIUS = 0.7f;

    /** The pattern that is displayed as a decal on the top of the tile */
    UTexture2D* TilePattern = nullptr;
    /** Reference to the tiles that are surrounding this tile */
    UPROPERTY(VisibleAnywhere, Category = "Surrounding Tiles")
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
    /** Set surrounding tiles that have not already been set */
    UFUNCTION(BlueprintCallable)
    void SetRemainingSurroundingTiles();
    /** Set tile to the left */
    void SetLeftSurroundingTile(ATile* LeftTile);
    /** Set tile to the right */
    void SetRightSurroundingTile(ATile* RightTile);

protected:
    /** Sends out a raycast in the supplied direction to see if there is a tile that is hit */
    bool FindTile(ATile*& OutHitTile, FVector RaycastDirection);
};

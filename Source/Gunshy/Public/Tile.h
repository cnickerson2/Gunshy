// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Tile.generated.h"

/** Forward Declarations */
class UTexture2D;

/**
 * A collection of the tiles that are surrounding this object
 */
USTRUCT(BlueprintType)
struct FSurroundingTiles
{
    GENERATED_USTRUCT_BODY()

    ATile* TileToTheLeft = nullptr;
    ATile* TileToTheRight = nullptr;
    ATile* TileOnTop = nullptr;
};

/**
 * 
 */
UCLASS()
class GUNSHY_API ATile : public AStaticMeshActor
{
    GENERATED_BODY()

#pragma region Fields and Properties
protected:
    UTexture2D* TilePattern = nullptr;
    // References to the tiles that are surrounding this tile
    FSurroundingTiles SurroundingTiles;

    // A global variable that stores the first tile that was selected so that it can be compared against the second selected
    static ATile* FirstSelectedTile;
#pragma endregion Fields and Properties
	
public:
    // Set this tile as selected
    virtual void SetAsSelected();
    // Clear this tile of it's selected properties
    virtual void RemoveAsSelected();
    // Remove the Tile from the board
    UFUNCTION(BlueprintCallable)
    virtual void RemoveTile();
    // Remove the Tile from the board
    UFUNCTION(BlueprintCallable)
    virtual void SetPattern(UTexture2D* NewPattern);
    // Returns true if the there is no tile on top, and no tile to at least one side
    bool IsAbleToBeSelected() const;
};

// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Tile.generated.h"

/**
 * The definition of the 32 different patterns that make up the 144 tile board
 */
UENUM(BlueprintType)
enum class ETilePattern : uint8
{
    Pattern0 = 0,
    Pattern1 = 1,
    Pattern2 = 2,
    Pattern3 = 3,
    Pattern4 = 4,
    Pattern5 = 5,
    Pattern6 = 6,
    Pattern7 = 7,
    Pattern8 = 8,
    Pattern9 = 9,
    Pattern10 = 10,
    Pattern11 = 11,
    Pattern12 = 12,
    Pattern13 = 13,
    Pattern14 = 14,
    Pattern15 = 15,
    Pattern16 = 16,
    Pattern17 = 17,
    Pattern18 = 18,
    Pattern19 = 19,
    Pattern20 = 20,
    Pattern21 = 21,
    Pattern22 = 22,
    Pattern23 = 23,
    Pattern24 = 24,
    Pattern25 = 25,
    Pattern26 = 26,
    Pattern27 = 27,
    Pattern28 = 28,
    Pattern29 = 29,
    Pattern30 = 30,
    Pattern31 = 31
};

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
    ETilePattern TilePattern;
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
    virtual void SetPattern(ETilePattern NewPattern);
    // Returns true if the there is no tile on top, and no tile to at least one side
    bool IsAbleToBeSelected() const;
};

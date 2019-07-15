// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Tile.generated.h"

/**
 * A collection of the tiles that are surrounding this object
 */
USTRUCT()
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
    FSurroundingTiles SurroundingTiles;
#pragma endregion Fields and Properties
	
public:
    virtual void SetSelected();
    // Returns true if the there is no tile on top, and no tile to at least one side
    bool IsAbleToBeSelected() const;
};

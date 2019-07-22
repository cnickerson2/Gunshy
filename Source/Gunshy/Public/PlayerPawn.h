// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

/// Forward Declarations
class ATile;
class UCameraComponent;
class UInputComponent;

/**
 * Defines the Player, including their camera and selection action
 */
UCLASS()
class GUNSHY_API APlayerPawn : public APawn
{
	GENERATED_BODY()

/// Fields and Properties
protected:
    /** How far down does the raycast go from the point on the camera that was selected */
    float const RAY_CAST_DISTANCE = 1000.0f;

    /** Default Player Camera */ 
    UPROPERTY(Category = "Camera", EditAnywhere)
    UCameraComponent * PlayerCamera = nullptr; 

#if PLATFORM_ANDROID || PLATFORM_IOS
    /** Gets the down state of the touch input */
     bool bIsCurrentlyPressed = false;
#endif

/// Methods
public:
	/** Sets default values for this pawn's properties */
	APlayerPawn();

	/** Called to bind functionality to input */
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    /** Attempt to select a tile */
    virtual void SelectAtClick();
    /** Deproject the Mouse Position of the Player Controller and cast a ray downwards towards the objects below */
    bool RaycastFromMousePosition(FHitResult& OutHitResult) const;
    /** Tell the tile that is passed in that it was selected */
    void InformTileOfSelection(ATile*& OutHitTile) const;
};

// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

#pragma region Forward Declarations
class UCameraComponent;
class UInputComponent;
#pragma endregion Forward Declarations

UCLASS()
class GUNSHY_API APlayerPawn : public APawn
{
	GENERATED_BODY()
#pragma region Fields and Properties
protected:
    // Default Player Camera
    UPROPERTY(Category = "Camera", BlueprintReadOnly)
        UCameraComponent * PlayerCamera = nullptr; // TODO: Figure out the bug here where VisibleAnywhere is allowing this to be edited...
#pragma endregion Fields and Properties

#pragma region Methods
public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    // Attempt to select a tile
    virtual void Select();
#pragma endregion Methods
};

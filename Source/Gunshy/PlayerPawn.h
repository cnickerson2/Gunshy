// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"


class UCameraComponent;

UCLASS()
class GUNSHY_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    // Default Player Camera
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Camera")
    UCameraComponent * PlayerCamera = nullptr;

};

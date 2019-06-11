// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;

    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


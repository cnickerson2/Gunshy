// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;

    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
    PlayerCamera->RelativeLocation = FVector(0, 0, 300); // Three meters up
    PlayerCamera->RelativeRotation = FRotator(0, -90, 0); // Look down
    PlayerCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);

}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind clicks
    PlayerInputComponent->BindAction("Click", IE_Pressed, this, &APlayerPawn::Select);


}

void APlayerPawn::Select()
{
    // Cast a ray from the Click position (either mouse or touch) downwards to see if you hit a tile

        // Tell the tile that it was selected

}



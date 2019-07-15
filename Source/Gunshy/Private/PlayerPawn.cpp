// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerController.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;

    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
    PlayerCamera->RelativeLocation = FVector(0, 0, DISTANCE_FROM_GROUND); // Three meters up
    PlayerCamera->RelativeRotation = FRotator(0, -90, 0); // Look down
    //PlayerCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);

}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind clicks
    PlayerInputComponent->BindAction("Click", IE_Pressed, this, &APlayerPawn::OnSelect);


}

void APlayerPawn::OnSelect()
{
    // Find the Click position (either mouse or touch) 
    APlayerController* PlayerController = Cast<APlayerController>(GetController());
    if (PlayerController == nullptr)
    {
        // Not a player
        return;
    }

    FVector RayStartingPosition, RayDirection;
    float MousePositionX, MousePositionY;

#if PLATFORM_WINDOWS
    PlayerController->GetMousePosition(MousePositionX, MousePositionY);
#elif PLATFORM_ANDROID || PLATFORM_IOS
    bool bIsCurrentlyPressed; // Don't care as this is called only on an action down, so it's not doing anything other than being required by GetInputTouchState
    PlayerController->GetInputTouchState(ETouchIndex::Touch1, MousePositionX, MousePositionY, bIsCurrentlyPressed);
#endif

    PlayerController->DeprojectScreenPositionToWorld(MousePositionX, MousePositionY, RayStartingPosition, RayDirection);

    // Cast a ray from the Click position downwards to see if you hit a tile
    FHitResult HitResult;
    bool bHasHit = GetWorld()->LineTraceSingleByObjectType(
        HitResult,
        RayStartingPosition,
        RayStartingPosition + RayDirection * RAY_CAST_DISTANCE,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_GameTraceChannel1) // Tile object type
    );
    if(bHasHit)
    {
        // Tell the tile that it was selected

        UE_LOG(LogTemp, Warning, TEXT("[%s] : Has Hit = [%s]"), *GetName(), *HitResult.ToString());
    }


}



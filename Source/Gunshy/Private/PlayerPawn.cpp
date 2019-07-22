// Created 2019 by Chris Nickerson. This game is intended to be free and therefore the code is not restricted.


#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tile.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;

    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
    PlayerCamera->RelativeRotation = FRotator(0, -90, 0); // Look down

}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Click", IE_Pressed, this, &APlayerPawn::SelectAtClick);
}

void APlayerPawn::SelectAtClick()
{
    FHitResult HitResult;
    bool bRaycastHitTile = RaycastFromMousePosition(HitResult);

    if(bRaycastHitTile)
    {
        ATile* TileThatWasHit = Cast<ATile>(HitResult.GetActor());
        if (TileThatWasHit)
        {
            InformTileOfSelection(TileThatWasHit);
        }
    }
}

bool APlayerPawn::RaycastFromMousePosition(FHitResult& OutHitResult) const
{    
    const APlayerController* PlayerController = Cast<APlayerController>(GetController());
    if (PlayerController == nullptr)
    {
        return false;
    }

    FVector RayStartingPosition, RayDirection;
    float MousePositionX, MousePositionY;

#if PLATFORM_DESKTOP || PLATFORM_WINDOWS || PLATFORM_APPLE
    PlayerController->GetMousePosition(MousePositionX, MousePositionY);

#elif PLATFORM_ANDROID || PLATFORM_IOS
    PlayerController->GetInputTouchState(ETouchIndex::Touch1, MousePositionX, MousePositionY, bIsCurrentlyPressed);

#endif

    PlayerController->DeprojectScreenPositionToWorld(MousePositionX, MousePositionY, RayStartingPosition, RayDirection);

    // Cast a ray from the Click position downwards to see if you hit a tile
    return GetWorld()->LineTraceSingleByObjectType(
        OutHitResult,
        RayStartingPosition,
        RayStartingPosition + RayDirection * RAY_CAST_DISTANCE,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_GameTraceChannel1) // Tile object type
    );
}

void APlayerPawn::InformTileOfSelection(ATile*& OutHitTile) const
{
    OutHitTile->SetAsSelected();
}
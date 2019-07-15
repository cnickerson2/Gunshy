// Fill out your copyright notice in the Description page of Project Settings.


#include "GunshyGameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

#if PLATFORM_DESKTOP || PLATFORM_WINDOWS || PLATFORM_APPLE
void AGunshyGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    FConstPlayerControllerIterator PlayerControllerIterator = GetWorld()->GetPlayerControllerIterator();

    for (FConstPlayerControllerIterator PlayerControllerIterator = GetWorld()->GetPlayerControllerIterator(); PlayerControllerIterator; ++PlayerControllerIterator)
    {
        APlayerController* PlayerController = Cast<APlayerController>(*PlayerControllerIterator);
        if (PlayerController) 
        {
            PlayerController->bShowMouseCursor = true;
            PlayerController->bEnableClickEvents = true;
            PlayerController->bEnableMouseOverEvents = true;
        }
    }
    
}
#endif

// Fill out your copyright notice in the Description page of Project Settings.


#include "GunshyGameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Public/TilePool.h"

AGunshyGameModeBase::AGunshyGameModeBase()
{
    TilePool = CreateDefaultSubobject<UTilePool>(TEXT("Tile Pool"));
}

void AGunshyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Display the mouse on Computer
#if PLATFORM_DESKTOP || PLATFORM_WINDOWS || PLATFORM_APPLE
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
#endif
}

void AGunshyGameModeBase::InitializePool()
{    
#if UE_BUILD_DEBUG
    if (Patterns.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("[%s] : No Patterns have been added, so no tiles will be spawned"), *GetName());
        return;
    }
#endif     

    TilePool->InitializePool(Patterns, TilesPerPattern);    
}



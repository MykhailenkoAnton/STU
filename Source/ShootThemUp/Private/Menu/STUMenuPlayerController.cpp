// Shoot Them Up Game, All Rights Reserved.


#include "Menu/STUMenuPlayerController.h"
#include "STUGameInstance.h" // for test

void ASTUMenuPlayerController::BeginPlay() 
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;

    GetWorld()->GetGameInstance<USTUGameInstance>()->TestString = "Menu level says hello"; // for test
}
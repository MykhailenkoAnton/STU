// Shoot Them Up Game, All Rights Reserved.

#include "Player/STUPlayerController.h"
#include "Components/STUPespawnComponent.h"

ASTUPlayerController::ASTUPlayerController() 
{
    RespawnComponent = CreateDefaultSubobject<USTUPespawnComponent>("STUPespawnComponent");
}
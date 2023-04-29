// Shoot Them Up Game, All Rights Reserved.


#include "Components/STUPespawnComponent.h"
#include "STUGameModeBase.h"

// Sets default values for this component's properties
USTUPespawnComponent::USTUPespawnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void USTUPespawnComponent::Respawn(int32 RespawnTime) 
{
    if (!GetWorld()) return;

	RespawnCountDown = RespawnTime;
    GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &USTUPespawnComponent::RespawnTimerUpdate, 1.0f, true);
}

void USTUPespawnComponent::RespawnTimerUpdate() 
{
    if (--RespawnCountDown == 0)
    {
        if (!GetWorld()) return;
        GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);

        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        if (!GameMode) return;

        GameMode->RespawnRequest(Cast<AController>(GetOwner()));
    }

}

bool USTUPespawnComponent::IsRespawnInProgress() const 
{
    return GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(RespawnTimerHandle);
}
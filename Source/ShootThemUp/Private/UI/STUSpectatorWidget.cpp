// Shoot Them Up Game, All Rights Reserved.


#include "UI/STUSpectatorWidget.h"
#include "STUUtils.h"
#include "Components/STUPespawnComponent.h"

bool USTUSpectatorWidget::GetRespawnTime(int32& CountDownTime) const
{
    const auto RespawnComponent = STUUtils::GetSTUPlayerComponent<USTUPespawnComponent>(GetOwningPlayer());
    if (!RespawnComponent || !RespawnComponent->IsRespawnInProgress()) return false;

    CountDownTime = RespawnComponent->GetRespawnCountDown();

    return true;
}

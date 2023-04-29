// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUPespawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMUP_API USTUPespawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USTUPespawnComponent();

	void Respawn(int32 RespawnTime);

	int32 GetRespawnCountDown() { return RespawnCountDown; }

	bool IsRespawnInProgress() const;

protected:
private:

	FTimerHandle RespawnTimerHandle;

	int32 RespawnCountDown = 0;

	void RespawnTimerUpdate();
};

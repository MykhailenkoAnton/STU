#pragma once
#include "Player/STUPlayerState.h"

class STUUtils
{
public:
    template <typename T>
    static T* GetSTUPlayerComponent(AActor* PlayerPawn)
    {
        if (!PlayerPawn) return nullptr;

        const auto Component = PlayerPawn->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }

    bool static AreEnemies(AController* Contoller1, AController* Contoller2) 
    { 
        if (!Contoller1 || !Contoller2 || Contoller1 == Contoller2) return false;

        const auto PlayerState1 = Cast<ASTUPlayerState>(Contoller1->PlayerState);
        const auto PlayerState2 = Cast<ASTUPlayerState>(Contoller2->PlayerState);

        return PlayerState1 && PlayerState2 && PlayerState1->GetTeamID() != PlayerState2->GetTeamID();
    }
};

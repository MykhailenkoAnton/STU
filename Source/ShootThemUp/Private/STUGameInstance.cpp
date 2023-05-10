// Shoot Them Up Game, All Rights Reserved.

#include "STUGameInstance.h"
#include "Sound/STUSoundFuncLib.h"

void USTUGameInstance::ToogleVolume() 
{
    USTUSoundFuncLib::ToggleSoundClassVolume(MasterSoundClass);
}

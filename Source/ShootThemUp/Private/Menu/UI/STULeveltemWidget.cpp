// Shoot Them Up Game, All Rights Reserved.


#include "Menu/UI/STULeveltemWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void USTULeveltemWidget::NativeOnInitialized() 
{
    if (LevelSelectButton)
    {
        LevelSelectButton->OnClicked.AddDynamic(this, &USTULeveltemWidget::OnLevelItemClicked);
    }
}

void USTULeveltemWidget::SetLevelData(const FLevelData& NewLevelData)
{
    LevelData = NewLevelData;

    if (LevelNameTextBlock)
    {
        LevelNameTextBlock->SetText(FText::FromName(NewLevelData.LevelDispayName));
    }

    if (LevelImage)
    {
        LevelImage->SetBrushFromTexture(NewLevelData.LevelThumb);
    }
}

void USTULeveltemWidget::SetSelected(bool IsSelected) 
{
    if (FrameImage)
    {
        FrameImage->SetVisibility(IsSelected ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    }
}

void USTULeveltemWidget::OnLevelItemClicked() 
{
    OnLevelSelected.Broadcast(LevelData);
}
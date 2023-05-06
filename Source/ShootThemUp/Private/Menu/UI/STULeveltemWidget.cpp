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
        LevelSelectButton->OnHovered.AddDynamic(this, &USTULeveltemWidget::OnLevelItemHovered);
        LevelSelectButton->OnUnhovered.AddDynamic(this, &USTULeveltemWidget::OnLevelItemUnHovered);
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
    if (LevelImage)
    {
        LevelImage->SetColorAndOpacity(IsSelected ? FLinearColor::Red : FLinearColor::White);
    }
}

void USTULeveltemWidget::OnLevelItemClicked() 
{
    OnLevelSelected.Broadcast(LevelData);
}

void USTULeveltemWidget::OnLevelItemUnHovered() 
{
    if (FrameImage)
    {
        FrameImage->SetVisibility(ESlateVisibility::Hidden);
    }
}

void USTULeveltemWidget::OnLevelItemHovered() 
{
    if (FrameImage)
    {
        FrameImage->SetVisibility(ESlateVisibility::Visible);
    }
}
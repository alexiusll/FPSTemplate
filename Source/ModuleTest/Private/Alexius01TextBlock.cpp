// Fill out your copyright notice in the Description page of Project Settings.


#include "Alexius01TextBlock.h"

void UAlexius01TextBlock::SetText(FText InText)
{
	Text = FText::Format(InText , prefix);

	TextDelegate.Unbind();
	if (MyTextBlock.IsValid())
	{
		TAttribute<FText> TextBinding = GetDisplayText();
		MyTextBlock->SetText(TextBinding);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "Alexius01TextBlock.h"
#include "SlateCore\Private\Fonts\FontCacheFreeType.h"

void UAlexius01TextBlock::preText()
{

}

void UAlexius01TextBlock::SetText(FText InText)
{
	Text = InText;

	TextDelegate.Unbind();
	if (MyTextBlock.IsValid())
	{
		TAttribute<FText> TextBinding = GetDisplayText();
		MyTextBlock->SetText(TextBinding);
	}
}

TAttribute<FText> UAlexius01TextBlock::GetDisplayText()
{
	// FText newText = FText::FromString(TEXT("233"));
	// Text = newText;

	return PROPERTY_BINDING(FText, Text);
}

//void UAlexius01TextBlock::fontHelp() {
//	UE_LOG(LogTemp, Display, TEXT("--- run freetype ---"));
//
//	FT_Library  mylibrary;
//	FT_Error error = FT_Init_FreeType(&mylibrary);
//	if (error)
//	{
//		UE_LOG(LogTemp, Error, TEXT("freetype failed!"));
//	}
//
//	Font.GetCompositeFont()->DefaultTypeface;
//}
// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEditableText.h"
#include "SlateCore/Public/Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Input/SEditableText.h"

void UMyEditableText::HandleOnTextChanged(const FText& InText)
{
	// ÷¥––‘§¥¶¿Ì
	FText newText = InText;
	OnTextChanged.Broadcast(newText);
}

TSharedRef<SWidget> UMyEditableText::RebuildWidget()
{
	MyEditableText = SNew(SEditableText)
		.Style(&WidgetStyle)
		.MinDesiredWidth(MinimumDesiredWidth)
		.IsCaretMovedWhenGainFocus(IsCaretMovedWhenGainFocus)
		.SelectAllTextWhenFocused(SelectAllTextWhenFocused)
		.RevertTextOnEscape(RevertTextOnEscape)
		.ClearKeyboardFocusOnCommit(ClearKeyboardFocusOnCommit)
		.SelectAllTextOnCommit(SelectAllTextOnCommit)
		.OnTextChanged(BIND_UOBJECT_DELEGATE(FOnTextChanged, HandleOnTextChanged))
		.OnTextCommitted(BIND_UOBJECT_DELEGATE(FOnTextCommitted, HandleOnTextCommitted))
		.VirtualKeyboardType(EVirtualKeyboardType::AsKeyboardType(KeyboardType.GetValue()))
		.VirtualKeyboardOptions(VirtualKeyboardOptions)
		.VirtualKeyboardTrigger(VirtualKeyboardTrigger)
		.VirtualKeyboardDismissAction(VirtualKeyboardDismissAction)
		.Justification(Justification);

	return MyEditableText.ToSharedRef();
}
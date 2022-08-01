// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableText.h"
#include "MyEditableText.generated.h"

/**
 * 
 */
UCLASS()
class FPSTEMPLATE_API UMyEditableText : public UEditableText
{
	GENERATED_BODY()


protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	void HandleOnTextChanged(const FText& Text);
};

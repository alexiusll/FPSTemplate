// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableTextBox.h"
#include "MyEditableTextBox.generated.h"

/**
 * 
 */
UCLASS()
class MODULETEST_API UMyEditableTextBox : public UEditableTextBox
{
	GENERATED_BODY()

protected:
	virtual void HandleOnTextChanged(const FText& Text);
};

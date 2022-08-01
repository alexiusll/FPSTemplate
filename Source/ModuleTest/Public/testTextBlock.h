// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "testTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class MODULETEST_API UtestTextBlock : public UTextBlock
{
	GENERATED_BODY()

	virtual void PostLoad() override;
};

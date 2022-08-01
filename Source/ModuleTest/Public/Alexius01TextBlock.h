// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Alexius01TextBlock.generated.h"

/**
 * 
 */
UCLASS()
class MODULETEST_API UAlexius01TextBlock : public UTextBlock
{
	GENERATED_BODY()

public:
	/** The text to display */
	UPROPERTY(EditAnywhere, Category = "Alexiusll")
	FText prefix;

	UPROPERTY(VisibleAnywhere, Category = "Alexiusll")
	FText finalText;

	//UFUNCTION(BlueprintCallable, Category = "alexiusll")
	//void fontHelp();

	void preText();

	virtual void SetText(FText InText) override;

protected:
	virtual TAttribute<FText> GetDisplayText() override;
};

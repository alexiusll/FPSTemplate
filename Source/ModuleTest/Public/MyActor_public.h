// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyActor_public.generated.h"


UCLASS()
class MODULETEST_API AMyActor_public : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor_public();

	/** The text to display */
	UPROPERTY(EditAnywhere, Category = "Alexiusll")
	FText text;

	/** The font to render the text with */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Alexiusll")
	FSlateFontInfo Font;

	UPROPERTY()
		FString test;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// text ‘§¥¶¿Ì
	void preTextDisplay();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// test freeType
	UFUNCTION(BlueprintCallable, Category = "alexiusll")
	void testFreeType();

	UFUNCTION(BlueprintCallable, Category = "alexiusll")
	void DisplayText();
};

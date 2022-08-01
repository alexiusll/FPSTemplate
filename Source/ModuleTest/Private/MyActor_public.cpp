// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor_public.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActor_public::AMyActor_public()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor_public::BeginPlay()
{
	Super::BeginPlay();

	// GEngine->AddOnScreenDebugMessage(0, 10.0f, FColor::Blue, TEXT("My Actor BeginPlay() new"));

#if WITH_FREETYPE
	GEngine->AddOnScreenDebugMessage(1, 10.0f, FColor::Blue, text.ToString());

	// FT_Get_Char_Index();
#endif	// WITH_FREETYPE
	
}

void AMyActor_public::preTextDisplay()
{

}

// Called every frame
void AMyActor_public::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor_public::testFreeType() {

}

void AMyActor_public::DisplayText() {
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, text.ToString());
}



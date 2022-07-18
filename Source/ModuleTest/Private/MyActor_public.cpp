// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor_public.h"

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

	GEngine->AddOnScreenDebugMessage(0, 10.0f, FColor::Blue, TEXT("My Actor"));
	
}

// Called every frame
void AMyActor_public::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


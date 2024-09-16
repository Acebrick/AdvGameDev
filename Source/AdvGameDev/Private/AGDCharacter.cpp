// Fill out your copyright notice in the Description page of Project Settings.


#include "AGDCharacter.h"

// Sets default values
AAGDCharacter::AAGDCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAGDCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


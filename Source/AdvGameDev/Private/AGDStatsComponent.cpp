// Fill out your copyright notice in the Description page of Project Settings.


#include "AGDStatsComponent.h"

// Sets default values for this component's properties
UAGDStatsComponent::UAGDStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	maxHealth = 100.0f;
	health = maxHealth;

	maxEnergy = 100.0f;
	energy = maxEnergy;

	minBaseDamage = 1;
	maxBaseDamage = 3;

	attackSpeed = 1.0f;
}


// Called when the game starts
void UAGDStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}
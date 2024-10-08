// Fill out your copyright notice in the Description page of Project Settings.


#include "AGDStatsComponent.h"

// Sets default values for this component's properties
UAGDStatsComponent::UAGDStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	isStatsInitialised = false;

	maxHealth = 100.0f;
	health = maxHealth;

	maxEnergy = 100.0f;
	energy = maxEnergy;

	minBaseDamage = 1;
	maxBaseDamage = 3;

	attackSpeed = 1.0f;

	characterLevel = 0;
	experience = 0;
	
	for (int i = 1; i < 10; i++)
	{
		experiencePerLevel.Add(i * 1000);
	}
}


// Called when the game starts
void UAGDStatsComponent::BeginPlay()
{
	health = maxHealth;
	energy = maxEnergy;

	Super::BeginPlay();

	UpdateCharacterLevel();
	isStatsInitialised = true;
}

int UAGDStatsComponent::GetMaxExperience()
{
	int maxExperience = 0;

	for (int levelExperience : experiencePerLevel)
	{
		maxExperience += levelExperience;
	}

	return maxExperience;
}

void UAGDStatsComponent::HandleLevelUp()
{
	SetMaxHealth(maxHealth * 2);
	SetHealth(maxHealth);

	SetMaxEnergy(maxEnergy + 10);
	SetEnergy(maxEnergy);

	int newMinDamage = minBaseDamage + 5;
	int newMaxDamage = maxBaseDamage + (5 + characterLevel);

	SetBaseDamage(newMinDamage, newMaxDamage);

	SetAttackSpeed(attackSpeed + 0.1f);

	// Run the blueprint event and pass through the level and stats initialised
	OnLevelUp(characterLevel, isStatsInitialised);
}

void UAGDStatsComponent::UpdateCharacterLevel()
{
	// If the character is max level then exit the function
	if (characterLevel + 1 > experiencePerLevel.Num())
		return;
	
	int newLevel = 0;
	int collectiveExperience = 0;

	// Increase levels based on experience
	for (int levelExperience : experiencePerLevel)
	{
		// Add collective experience by the amount of level experience
		collectiveExperience += levelExperience;

		// If our actual experience is less than the collective experience end the loop
		if (experience < collectiveExperience)
			break;

		// Increment level
		newLevel++;

		// If the level increases then handle level up
		if (newLevel > characterLevel)
			HandleLevelUp(); 
	}

	// Update character level if the new level is different
	if (newLevel != characterLevel)
		characterLevel = newLevel;
}

void UAGDStatsComponent::AddExperience(int amount)
{
	// Adding amount to experience than clamping it between 0 and max possible experience
	int newExperience = FMath::Clamp(experience + amount, 0, GetMaxExperience());
	
	SetExperience(newExperience);
}

void UAGDStatsComponent::SetExperience(int newExperience)
{
	// Adding amount to experience than clamping it between 0 and max possible experience
	int localNewExperience = FMath::Clamp(newExperience, 0, GetMaxExperience());

	experience = localNewExperience; 

	UpdateCharacterLevel();
}

void UAGDStatsComponent::GetDisplayLevelInfo(int& displayLevel, int& displayExperience)
{
	// Add one to the level to get a more readable character level
	displayLevel = characterLevel + 1;

	displayExperience = experience;

	// If the character is level one then end the function
	if (characterLevel <= 0)
		return;

	// Set our experience to zero if we are at max level
	if (displayExperience >= GetMaxExperience())
	{
		displayExperience = 0;
		return;
	}

	// Update display experience to remove all the previous levels experience for a cleaner number
	// This also allows for progress bars per level
	for (int i = 0; i < characterLevel; i++)
	{
		displayExperience -= experiencePerLevel[i];
	}
}

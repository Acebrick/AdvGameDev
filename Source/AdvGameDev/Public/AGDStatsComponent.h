// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AGDStatsComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ADVGAMEDEV_API UAGDStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAGDStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float maxHealth;

	float health;

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	float maxEnergy;

	float energy;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	int minBaseDamage;
	
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	int maxBaseDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Additional Stats")
	float attackSpeed;

	int characterLevel;

	UPROPERTY(EditDefaultsOnly, Category = "Levelling")
	int experience;

	UPROPERTY(EditDefaultsOnly, Category = "Levelling")
	TArray<int> experiencePerLevel; 

	int GetMaxExperience();

	void HandleLevelUp();

	bool isStatsInitialised;

public:
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetMaxHealth() const { return maxHealth; }
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetMaxHealth(float newMaxHealth) { maxHealth = newMaxHealth; }

	UFUNCTION(BlueprintPure, Category = "Energy")
	float GetMaxEnergy() const { return maxEnergy; }

	UFUNCTION(BlueprintCallable, Category = "Energy")
	void SetMaxEnergy(float newMaxEnergy) { maxEnergy = newMaxEnergy; }
	
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const { return health; }

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetHealth(float newHealth) { health = newHealth; }

	UFUNCTION(BlueprintPure, Category = "Energy")
	float GetEnergy() const { return energy; }

	UFUNCTION(BlueprintCallable, Category = "Energy")
	void SetEnergy(float newEnergy) { energy = newEnergy; }

	UFUNCTION(BlueprintPure, Category = "Damage")
	int GetBaseDamage() const { return FMath::RandRange(minBaseDamage, maxBaseDamage); }

	UFUNCTION(BlueprintCallable, Category = "Damage")
	void SetBaseDamage(int min, int max) { minBaseDamage = min; maxBaseDamage = max; }

	UFUNCTION(BlueprintPure, Category = "Additional Stats")
	float GetAttackSpeed() const { return attackSpeed; }

	UFUNCTION(BlueprintCallable, Category = "Additional Stats")
	void SetAttackSpeed(float newAttackSpeed) { attackSpeed = newAttackSpeed; } 

	UFUNCTION(BlueprintCallable, Category = "Levelling")
	void UpdateCharacterLevel();

	UFUNCTION(BlueprintCallable, Category = "Levelling")
	void AddExperience(int amount);

	UFUNCTION(BlueprintCallable, Category = "Levelling")
	void SetExperience(int newExperience);

	UFUNCTION(BlueprintImplementableEvent, Category = "Levelling")
	void OnLevelUp(int level, bool areStatsInitialised);

	UFUNCTION(BlueprintPure, Category = "Levelling")
	void GetTrueLevelInfo(int& trueLevel, int& trueExperience) { trueLevel = characterLevel; trueExperience = experience; }

	UFUNCTION(BlueprintPure, Category = "Levelling")
	void GetDisplayLevelInfo(int& displayLevel, int& displayExperience);

	UFUNCTION(BlueprintPure, Category = "Levelling")
	TArray<int> GetExperiencePerLevel() const { return experiencePerLevel; }
};
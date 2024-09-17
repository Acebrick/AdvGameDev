// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGDCharacter.h"
#include "AGDPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class ADVGAMEDEV_API AAGDPlayerCharacter : public AAGDCharacter
{
	GENERATED_BODY()
public:
	AAGDPlayerCharacter();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComponent;
	
	// Only let the player attack if this is true
	bool bAttackAllowed;

	// Force actor rotation to the camera
	bool bForceRotate;

	// The combo of the attack animation
	int attackCombo;

public:
	/* Set the boolean attackAllowed */
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SetAttackAllowed(bool bAllowAttack) { bAttackAllowed = bAllowAttack; }

	UFUNCTION(BlueprintPure, Category = "Combat")
	const bool GetAttackAllowed() { return bAttackAllowed; }

	UFUNCTION(BlueprintCallable, Category = "Rotation")
	void SetForceRotate(bool bShouldRotate) { bForceRotate = bShouldRotate; }

	UFUNCTION(BlueprintPure, Category = "Rotation")
	const bool GetForceRotate() { return bForceRotate; }

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SetAttackCombo(int newAttackCombo) { attackCombo = newAttackCombo; }

	UFUNCTION(BlueprintPure, Category = "Combat")
	const int getAttackCombo() { return attackCombo; }
};

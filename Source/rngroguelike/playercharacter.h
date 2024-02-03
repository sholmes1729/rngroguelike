// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "worldcharacter.h"
#include "playercharacter.generated.h"

/**
 * 
 */
UCLASS()
class RNGROGUELIKE_API Aplayercharacter : public Aworldcharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Aplayercharacter();

protected:
	// Called when the game starts or when spawned 
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Actuate() override;
	
};

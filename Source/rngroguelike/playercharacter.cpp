// Fill out your copyright notice in the Description page of Project Settings.


#include "playercharacter.h"

// Sets default values
Aplayercharacter::Aplayercharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aplayercharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void Aplayercharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Aplayercharacter::SetupPlayerInputComponent(UInputComponent* pc)
{
	Super::SetupPlayerInputComponent(pc);
	pc->BindAction("mleft", EInputEvent::IE_Pressed, this, &Aplayercharacter::Actuate);

}

void Aplayercharacter::Actuate() {
	if (!IsValid(enemy) || !IsValid(enemy->enemy) && !enemy->dead) {
		return;
	}
	Super::Actuate();
	enemy->Actuate();
}
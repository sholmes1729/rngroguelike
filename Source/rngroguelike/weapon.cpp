// Fill out your copyright notice in the Description page of Project Settings.


#include "weapon.h"

// Sets default values
Aweapon::Aweapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aweapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aweapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


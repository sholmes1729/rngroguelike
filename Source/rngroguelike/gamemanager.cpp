// Fill out your copyright notice in the Description page of Project Settings.


#include "gamemanager.h"
#include "kismet/gameplaystatics.h"
#include "worldcharacter.h"
#include "playercharacter.h"

// Sets default values
Agamemanager::Agamemanager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Agamemanager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Agamemanager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Agamemanager::GetAllDuellers() {


}
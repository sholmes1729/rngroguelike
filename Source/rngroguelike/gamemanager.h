// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "gamemanager.generated.h"

UCLASS()
class RNGROGUELIKE_API Agamemanager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Agamemanager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<class Aworldcharacter*> dueller; //should be sized 2

	void GetAllDuellers();

	int32 playerIndex = -1; //index of player in dueller array

};

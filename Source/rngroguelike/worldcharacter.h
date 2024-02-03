// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "worldcharacter.generated.h"

UENUM(BlueprintType) 
enum class EDt : uint8 {
	DT_NONE,
	DT_FREEZE,
	DT_BURN,
	DT_PIERCE
};

USTRUCT(BlueprintType)
struct FDamageStruct {
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) EDt damage_type = EDt::DT_NONE;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) float damage = 0.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) float accuracy = 100.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class Aworldcharacter* instantiated_by = nullptr;

};

UCLASS()
class RNGROGUELIKE_API Aworldcharacter : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	Aworldcharacter();

protected:
	// Called when the game starts or when spawned 
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	virtual void Actuate(); //called per turn
	void PostActuate();
	void CalculateStatusEffects(); //calculate status effects and damages
	void Attack();
	void ProcessDamageEvent(const FDamageStruct& damage_event);
	void InitializeStats();
	UFUNCTION(BlueprintCallable) void SetEnemy(Aworldcharacter* seen_enemy);
	UFUNCTION(BlueprintCallable) float Gethealth() { return health; }
	UFUNCTION(BlueprintCallable) float GetHealthPercent() { return health / max_health; }

	UFUNCTION(BlueprintImplementableEvent) void On_Actuate();
	UFUNCTION(BlueprintImplementableEvent) void On_Attack();
	UFUNCTION(BlueprintImplementableEvent) void On_TakeDamage(float damage);
	UFUNCTION(BlueprintImplementableEvent) void On_StatusEffectApplied(EDt status_effect_applied);



	/************************************************************************/
	//ATTRIBUTES

	float health = 100.f;
	float max_health = 100.f;

	//privdes health
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float strength = 5.f;

	//provides damage amp for magical effects
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float intelligence = 20.f;

	//provides accuracy and speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float agility = 20.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float physical_damage = 7.f;

	//physical damage reduction
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float physical_resistance = 5.f;

	//fire dmg reduction
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float fire_resistance = 10.f;

	//freeze dmg reduction
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float freeze_resistance = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float p_fire_chance = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float p_freeze_chance = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float p_pierce_chance = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float p_crit_chance = 17.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float p_crit_percent = 20.f;

	int32 value = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		Aworldcharacter* enemy = nullptr;

	FRandomStream rng;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) bool dead = false;


};

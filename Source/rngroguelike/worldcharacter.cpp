// Fill out your copyright notice in the Description page of Project Settings.


#include "worldcharacter.h"
#include "Misc/DateTime.h"

// Sets default values
Aworldcharacter::Aworldcharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aworldcharacter::BeginPlay()
{
	Super::BeginPlay();
	FDateTime Time = FDateTime::Now();
	int64 Timestamp = Time.ToUnixTimestamp();
	rng = FRandomStream(FMath::Rand());
	InitializeStats();
	
}

// Called every frame
void Aworldcharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (dead) {
		//Destroy();
	}
}

// Called to bind functionality to input
void Aworldcharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void Aworldcharacter::Actuate()
{
	if (!IsValid(enemy) || !IsValid(enemy->enemy)) {
		return; //no enemy 
	}
	if (dead) return;
	Attack();
	
}

void Aworldcharacter::PostActuate()
{

}

void Aworldcharacter::CalculateStatusEffects()
{

}

void Aworldcharacter::Attack()
{
	On_Attack();
	FDamageStruct dmgEvent;
	dmgEvent.damage_type = EDt::DT_NONE;
	float rand_can_crit = rng.FRandRange(0.f, 100.f);
	bool can_crit = rand_can_crit <= p_crit_chance;
	dmgEvent.damage = physical_damage;
	if (can_crit) {
		float crit_dmg = rng.FRandRange(1.f, p_crit_percent) / 100.f * physical_damage;
		dmgEvent.damage += crit_dmg;
	}
	dmgEvent.instantiated_by = this;
	UE_LOG(LogTemp, Warning, TEXT("%s does %f damage"), *(GetName()), dmgEvent.damage);
	enemy->ProcessDamageEvent(dmgEvent);
}

void Aworldcharacter::ProcessDamageEvent(const FDamageStruct& damage_event)
{
	float damage_taken = damage_event.damage;
	damage_taken = (damage_taken * damage_taken / (damage_taken + physical_resistance));
	health -= damage_taken;
	On_TakeDamage(damage_taken);
	if (health < 0.f) {
		UE_LOG(LogTemp, Warning, TEXT("%s died."), *GetName());
		//Destroy();
		dead = true;
		return;
	}
}

void Aworldcharacter::InitializeStats()
{
	//1 strength gives 20 hp
	strength = rng.FRandRange(25.f, 30.f);
	max_health = health = strength * 5.f;
	physical_damage = rng.FRandRange(27.f, 39.f);
	physical_resistance = rng.FRandRange(1.f, 2.f);

	p_crit_chance = rng.FRandRange(17, 27.f);
	p_crit_percent = rng.FRandRange(17.f, 27.f);

	agility = rng.FRandRange(20.f, 50.f); //TODO: DETEMINE  AFFECTED STATS


}

void Aworldcharacter::SetEnemy(Aworldcharacter* seen_enemy) {
	if (!IsValid(enemy)) {
		UE_LOG(LogTemp, Warning, TEXT("set new enemy %s"), *(seen_enemy->GetName()));
		enemy = seen_enemy;
	}
}
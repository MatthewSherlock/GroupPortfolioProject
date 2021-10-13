// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemy.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"	//for random in vol

// Sets default values
ASpawnEnemy::ASpawnEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawnEnemy::spawnAnEnemy() {
	if (GetWorld()) {
		FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		spawnParams.Instigator = GetInstigator();
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		FVector spawnLoc = this->GetActorLocation();
		FRotator rot = FRotator::ZeroRotator;
		AEnemy* enemy = GetWorld()->SpawnActor<AEnemy>(enemyClass, spawnLoc, rot, spawnParams);
		//enemy->baseLoc = spawnLoc;
	}
}

// Called when the game starts or when spawned
void ASpawnEnemy::BeginPlay()
{
	Super::BeginPlay();
	spawnAnEnemy();
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

ACoinSpawner::ACoinSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACoinSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnCoin();
}

void ACoinSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetAllCoins();
}

void ACoinSpawner::GetAllCoins()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ACoin::StaticClass(),Actors);
}

void ACoinSpawner::SpawnCoin()
{
	for(int i = 0; i < 10; i++)
	{
		GetWorld()->SpawnActor<ACoin>(Coin,FVector(FMath::RandRange(-1300,1300),
			FMath::RandRange(-1400,1400),220),FRotator::ZeroRotator);
	}
}


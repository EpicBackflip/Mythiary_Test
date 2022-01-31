// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinSpawner.h"

#include <algorithm>

#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "Mythiary_Test/Mythiary_TestCharacter.h"

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
	FindNearestObjectsToPlayer(Actors);
}

void ACoinSpawner::GetAllCoins()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ACoin::StaticClass(),Actors);
}

void ACoinSpawner::FindNearestObjectsToPlayer(TArray<AActor*> Objects)
{
	AMythiary_TestCharacter* Character = Cast<AMythiary_TestCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	FVector PlayerLocation = Character->GetActorLocation();
	float Distance;
	float Offset = 100;
	NearestDistance = 1000;
	for(int i = 0; i < Objects.Num(); i++)
	{
		Distance = (Objects[i]->GetActorLocation().Dist(Objects[i]->GetActorLocation(),PlayerLocation)-Offset)/Offset;
		if ((Distance) < NearestDistance)
		{
			NearestDistance = Distance;
		}
	}
}

void ACoinSpawner::SpawnCoin()
{
	for(int i = 0; i < 10; i++)
	{
		GetWorld()->SpawnActor<ACoin>(Coin,FVector(FMath::RandRange(-1300,1300),
			FMath::RandRange(-1400,1400),220),FRotator::ZeroRotator);
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Coin.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinSpawner.generated.h"

UCLASS()
class MYTHIARY_TEST_API ACoinSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ACoinSpawner();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere,Category = "Spawnable")
	TSubclassOf<ACoin> Coin;
	
private:
	void SpawnCoin();
};

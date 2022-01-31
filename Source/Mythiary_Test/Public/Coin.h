// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

class UBoxComponent;
UCLASS(config = Game)
class  ACoin : public AActor
{
	GENERATED_BODY()
public:	
	ACoin();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	UStaticMeshComponent* Coin;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	UBoxComponent* HitBox;

private:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
};


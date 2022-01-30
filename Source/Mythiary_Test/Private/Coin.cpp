// Fill out your copyright notice in the Description page of Project Settings.

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::White,String);
#include "Coin.h"

#include "Components/BoxComponent.h"
#include "Mythiary_Test/Mythiary_TestCharacter.h"

// Sets default values
ACoin::ACoin()
{
	Coin = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	RootComponent = Coin;
	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->SetupAttachment(Coin);

	PrimaryActorTick.bCanEverTick = true;
}
void ACoin::OnOverlap(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32  OtherbodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	AMythiary_TestCharacter* Character = Cast<AMythiary_TestCharacter>(OtherActor);
	if(Character)
	{
		Character->CoinsPickedUpInt++;
		Destroy();
	}
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	HitBox->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlap);
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


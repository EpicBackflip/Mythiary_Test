// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"

#include "CoinSpawner.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Mythiary_Test/Mythiary_TestCharacter.h"

void UScoreWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	UpdateScore();
	UpdateCoins();
}

void UScoreWidget::UpdateScore()
{
	AMythiary_TestCharacter* Character = Cast<AMythiary_TestCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	CoinsPickedUp->SetText(FText::AsNumber(Character->CoinsPickedUpInt));
}

void UScoreWidget::UpdateCoins()
{
	ACoinSpawner* CoinSpawner = Cast<ACoinSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(),ACoinSpawner::StaticClass()));
	CoinsLeft->SetText(FText::AsNumber(CoinSpawner->Actors.Num()));
}

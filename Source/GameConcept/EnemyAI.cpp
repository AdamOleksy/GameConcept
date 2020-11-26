// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnemyAI.h"

// Sets default values for this component's properties
UEnemyAI::UEnemyAI()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	
	if (WayPoint)
	{
		UE_LOG(LogTemp, Warning, TEXT("I have waypoint in location %s"), *WayPoint->GetTransform().ToString());
	}

	
	// ...
	
}


// Called every frame
void UEnemyAI::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		FRotator LookAtDirectiron = UKismetMathLibrary::FindLookAtRotation
		(
			GetOwner()->GetActorLocation(), 
			WayPoint->GetActorLocation()
		);

		LookAtDirectiron.Yaw = FMath::FInterpTo(GetOwner()->GetActorRotation().Yaw, LookAtDirectiron.Yaw, DeltaTime, 0.01f);
		UE_LOG(LogTemp, Warning, TEXT("Target direction %f"), LookAtDirectiron.Yaw);
		GetOwner()->SetActorRotation({0.f, LookAtDirectiron.Yaw, 0.f});

		

	// ...
}


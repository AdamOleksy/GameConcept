// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/Actor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/Quat.h"
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
	
	// ...
	
}


// Called every frame
void UEnemyAI::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveToWaypoint(DeltaTime);
	// ...
}

void UEnemyAI::MoveToWaypoint(float DeltaTime)
{
	if(WayPoint)
	{
		FRotator LookAtDirectiron = UKismetMathLibrary::FindLookAtRotation
		(
			GetOwner()->GetActorLocation(), 
			WayPoint->GetActorLocation()
		);

		FRotator NewRotation = FMath::RInterpTo(GetOwner()->GetActorRotation(), LookAtDirectiron, DeltaTime, RotationSpeed);
		GetOwner()->SetActorRotation({0.f, NewRotation.Yaw, 0.f});

		
		FVector ActorLocation = GetOwner()->GetActorLocation();
		ActorLocation += (GetOwner()->GetActorForwardVector() * DeltaTime * MovementSpeed);
		GetOwner()->SetActorLocation(ActorLocation);
	}

}


void UEnemyAI::PawnReachWayPoint()
{
	UE_LOG(LogTemp, Error, TEXT("Dotarlem do punktu %s"), *GetOwner()->GetName());
}

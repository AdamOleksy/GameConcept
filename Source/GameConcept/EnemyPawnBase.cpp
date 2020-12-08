// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawnBase.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "WaypointsList.h"


// Sets default values
AEnemyPawnBase::AEnemyPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule component"));
	CapsuleComponent->SetCollisionProfileName(TEXT("BlockAll"));
	CapsuleComponent->SetHiddenInGame(false);
	CapsuleComponent->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);
	Arrow->SetHiddenInGame(ArrowVisible);
}

// Called when the game starts or when spawned
void AEnemyPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToWaypoint(DeltaTime);

}

// Called to bind functionality to input
void AEnemyPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AEnemyPawnBase::MoveToWaypoint(float DeltaTime)
{
	AActor* TargetWayPoint = ListOfWaypoints->List[CurrentWaypoint];
	if(TargetWayPoint)
	{
		UE_LOG(LogTemp, Error, TEXT("Ruszam sie %s"), *TargetWayPoint->GetName());
		FRotator LookAtDirectiron = UKismetMathLibrary::FindLookAtRotation
		(
			GetActorLocation(), 
			TargetWayPoint->GetActorLocation()
		);

		FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), LookAtDirectiron, DeltaTime, RotationSpeed);
		SetActorRotation({0.f, NewRotation.Yaw, 0.f});

		FVector MoveDiraction = FVector(MovementSpeed * DeltaTime, 0, 0);
		AddActorLocalOffset(MoveDiraction, true);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No waypoint %s"), *GetName());
	}
	

}

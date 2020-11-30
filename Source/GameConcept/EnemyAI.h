// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyAI.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMECONCEPT_API UEnemyAI : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyAI();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	AActor* WayPoint;

	UPROPERTY(EditAnywhere)
	AActor* SecoundWayPoint;

	UFUNCTION(BlueprintCallable)
	void PawnReachWayPoint();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float RotationSpeed{1.f};

	UPROPERTY(EditAnywhere)
	float MovementSpeed{500.f};

	void MoveToWaypoint(float DeltaTime);

};

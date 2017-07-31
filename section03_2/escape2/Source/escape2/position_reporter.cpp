// Fill out your copyright notice in the Description page of Project Settings.

#include "position_reporter.h"
#include <GameFramework/Actor.h>

// Sets default values for this component's properties
Uposition_reporter::Uposition_reporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Uposition_reporter::BeginPlay()
{
	Super::BeginPlay();

    FString objectname = GetOwner()->GetName();
    //FString objectloc = GetOwner()->GetTargetLocation().ToString();
    FString objectloc = GetOwner()->GetTransform().GetLocation().ToString();
    UE_LOG(LogTemp, Warning, TEXT("[Jerry] PositionReport reporting...for %s, location 2 %s"), *objectname,*objectloc);

}


// Called every frame
void Uposition_reporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


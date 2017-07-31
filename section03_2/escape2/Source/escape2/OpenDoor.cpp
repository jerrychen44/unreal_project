// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include <GameFramework/Actor.h>

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//my_opendoor();
	owner = GetOwner();
	actorthatopens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UOpenDoor::my_opendoor()
{
	//AActor* owner = GetOwner();
	//FRotator newrotation = FRotator(0.0f, 140.0f, 0.0f);
	owner->SetActorRotation(FRotator(0.0f, openangle, 0.0f));
}


void UOpenDoor::my_closedoor()
{
	//AActor* owner = GetOwner();
	//FRotator newrotation = FRotator(0.0f, 140.0f, 0.0f);
	owner->SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (pressureplate->IsOverlappingActor(actorthatopens)) {
		my_opendoor();
		LastDoorOpenTIme = GetWorld()->GetTimeSeconds();
	}

	//check it is the time to close the door.
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTIme > DoorCloseDelay)
		my_closedoor();
}


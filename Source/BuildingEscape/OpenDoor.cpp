#include "OpenDoor.h"

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	Owner = GetOwner();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		ToggleDoor(true);
	}
	
	if (GetWorld()->GetTimeSeconds() - DoorLastOpenTime > DoorCloseDelay)
	{
		ToggleDoor(false);
	}
}

void UOpenDoor::ToggleDoor(const bool bOpen)
{
	Owner->SetActorRotation(FRotator(0.0f, bOpen ? OpenAngle : 0.0f, 0.0f));
	
	if (bOpen)
	{
		DoorLastOpenTime = GetWorld()->GetTimeSeconds();
	}
	else
	{
		DoorLastOpenTime = 0.0f;
	}
}

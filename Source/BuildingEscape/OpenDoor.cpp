#include "OpenDoor.h"

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    if (PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
        OpenDoor();
    }
}

void UOpenDoor::OpenDoor()
{
    AActor* Owner = GetOwner();
    FRotator NewRotator = FRotator(0.0f, -60.0f, 0.0f);
    Owner->SetActorRotation(NewRotator);
}

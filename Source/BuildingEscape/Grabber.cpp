#include "Grabber.h"

#define OUT

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	Owner = GetOwner();
}

void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"))
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// Get player view point this tick.
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotator);
	
	UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s\n"),
		*PlayerViewPointLocation.ToString(),
		*PlayerViewPointRotator.ToString())
	
	// Ray-cast out to reach distance.
	
	// See what we hit.
}

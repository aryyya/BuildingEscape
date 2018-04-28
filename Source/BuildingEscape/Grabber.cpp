#include "Grabber.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
//#include "Runtime/Engine/Classes/Engine/World.h"

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
		
	// Draw a red trace in the world to visualize the reach.
	const FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotator.Vector() * Reach;
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.0f,
		0,
		1.0f);
	
	// Setup query parameters.
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	
	// Line-trace (ray-cast) out to reach distance.
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters);
	
	// See what we hit.
	const AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitActor->GetName())
	}
}

#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();
	
	const AActor* Owner = GetOwner();
	const FString Name = Owner->GetName();
	const FVector Location = Owner->GetActorLocation();
	const FString Position = FString::Printf(TEXT("X=%f Y=%f Z=%f"), Location.X, Location.Y, Location.Z);
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *Name, *Position)
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}


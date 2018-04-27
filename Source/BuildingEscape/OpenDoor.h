#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()
    
public:
	UOpenDoor();
    
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere)
    float OpenAngle = 90.0f;

    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
    
    AActor* ActorThatOpens;
    
    void OpenDoor();
};

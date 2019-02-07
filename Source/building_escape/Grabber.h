// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UGrabber();
    // Called when the game starts
    virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
private:
    float Reach = 100.f;
    UPhysicsHandleComponent* PhysicsHandle = nullptr;
    UInputComponent* InputComponent = nullptr;
    void Grab();
    // called when grab is released
    void Release();
    void FindPhysicsHandleComponent();
    void SetupInputComponent();
    const FHitResult GetFirstPhysicsBodyInReach();
    FVector GetReachLineTraceStart();
    FVector GetReachLineTraceEnd();
};

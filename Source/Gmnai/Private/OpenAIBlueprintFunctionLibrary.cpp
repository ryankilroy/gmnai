// Copyright (C) 2023 Ryan Kilroy <ryanmkilroy@gmail.com>  * This file is part of Gmnai * Gmnai can not be copied and/or distributed without the express permission of Ryan Kilroy


#include "OpenAIBlueprintFunctionLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

void UOpenAIBlueprintFunctionLibrary::AddRandomStaticMeshComponent(AActor* TargetActor)
{
    if (!TargetActor) return;

    // Load the Cube and Sphere static meshes at runtime
    UStaticMesh* CubeMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube")));
    UStaticMesh* SphereMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere")));

    if (!CubeMesh || !SphereMesh) return;

    // Create a new StaticMeshComponent
    UStaticMeshComponent* NewMeshComponent = NewObject<UStaticMeshComponent>(TargetActor);
    if (!NewMeshComponent) return;

    // Randomly select between Cube and Sphere
    NewMeshComponent->SetStaticMesh(FMath::RandBool() ? CubeMesh : SphereMesh);

    // Attach the new component to the actor
    NewMeshComponent->AttachToComponent(TargetActor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
    NewMeshComponent->RegisterComponent();
}

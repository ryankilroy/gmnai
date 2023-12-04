// Copyright (C) 2023 Ryan Kilroy <ryanmkilroy@gmail.com>  * This file is part of Gmnai * Gmnai can not be copied and/or distributed without the express permission of Ryan Kilroy

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OpenAIBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GMNAI_API UOpenAIBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
		UFUNCTION(BlueprintCallable, Category="Mesh Modification")
    static void AddRandomStaticMeshComponent(AActor* TargetActor);
};

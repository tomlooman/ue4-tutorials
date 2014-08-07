
#pragma once

#include "UsableActor.generated.h"


UCLASS()
class AUsableActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

	// The functions return a boolean to force Unreal to recognize it as Functions instead of Events so they can be overriden in child classes.
	// This is an issue that will be fixed in a future release of Unreal.

	UFUNCTION(BlueprintImplementableEvent)
	bool OnUsed(ACharacter* character);

	UFUNCTION(BlueprintImplementableEvent)
	bool StartFocusItem();

	UFUNCTION(BlueprintImplementableEvent)
	bool EndFocusItem();
};
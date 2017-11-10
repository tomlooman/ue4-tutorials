// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once 

#include "GameFramework/HUD.h"
#include "TutorialsHUD.generated.h"

UCLASS()
class TUTORIALS_API ATutorialsHUD : public AHUD
{
	GENERATED_BODY()

public:

	ATutorialsHUD(const class FObjectInitializer& PCIP);

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	UTexture2D* CrosshairTex;

};


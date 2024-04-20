// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class TGameFPSServerTarget : TargetRules
{
    public TGameFPSServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		//BuildEnvironment = TargetBuildEnvironment.Shared;
		ExtraModuleNames.Add("TGameFPS");
	}
}

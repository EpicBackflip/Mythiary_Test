// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Mythiary_Test : ModuleRules
{
	public Mythiary_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

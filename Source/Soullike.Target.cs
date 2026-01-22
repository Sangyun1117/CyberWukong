using UnrealBuildTool;
using System.Collections.Generic;

public class SoullikeTarget : TargetRules
{
	public SoullikeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("Soullike");
	}
}

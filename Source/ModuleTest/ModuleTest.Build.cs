using UnrealBuildTool;

public class ModuleTest : ModuleRules
{
	public ModuleTest(ReadOnlyTargetRules Target) : base(Target)
	{
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "UMG" , "Slate"});

		if (Target.Type != TargetType.Server)
		{
			if (Target.bCompileFreeType)
			{
				AddEngineThirdPartyPrivateStaticDependencies(Target, "FreeType2");
				PublicDefinitions.Add("WITH_FREETYPE=1");
			}
			else
			{
				PublicDefinitions.Add("WITH_FREETYPE=0");
			}

			//if (Target.bCompileICU)
			//{
			//	AddEngineThirdPartyPrivateStaticDependencies(Target, "ICU");
			//}

			//AddEngineThirdPartyPrivateStaticDependencies(Target, "HarfBuzz");
		}
		else
		{
			PublicDefinitions.Add("WITH_FREETYPE=0");
			// PublicDefinitions.Add("WITH_HARFBUZZ=0");
		}
	}
}

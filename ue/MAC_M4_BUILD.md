# Diabolic UE build — macOS Pro M4 Max (2024)

Editor only. Do not install Discord or X during the deep-work block.

## Machine

- Chip: Apple M4 Max. Build arm64 only. Do not cross-compile Win64 until the combat slice plays.
- Xcode: 16.x from the App Store. After install: `sudo xcode-select -s /Applications/Xcode.app` then `xcodebuild -runFirstLaunch`.
- Unreal: Epic Launcher Apple Silicon build, UE 5.5 or 5.6. Install to `/Users/Shared/Epic Games/UE_5.5`.
- Disk: keep the project on the internal SSD. DerivedData and Intermediate will eat 20–40 GB.

## First editor session (tomorrow objective 1)

1. Epic Launcher → UE 5.5 → Games → Blank → C++ → name `Diabolic` → desktop, scalable, no starter content.
2. Close the editor.
3. Copy `ue/Source/Diabolic/Combat/*` into the new project's `Source/Diabolic/Combat/`.
4. In `Diabolic.Build.cs` add:

```csharp
PublicDependencyModuleNames.AddRange(new[] {
    "Core", "CoreUObject", "Engine", "InputCore",
    "GameplayAbilities", "GameplayTags", "GameplayTasks"
});
```

5. In `Diabolic.uproject` add plugins `GameplayAbilities` (enabled).
6. Right-click `Diabolic.uproject` → Generate Xcode Project, or:

```bash
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
```

7. Build:

```bash
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

M4 Max: use `-maxparallelactions` default. First compile is 15–40 min. Later increments are minutes.

## Deep-work rule

One feature. Today that feature is the attribute set. Do not open the node-farm landing page during the combat block.

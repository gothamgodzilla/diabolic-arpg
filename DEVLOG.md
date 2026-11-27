# DIABOLIC ARPG — DEVLOG

## 2026-11-27 09:15 AM PST

**Review of latest (b50fc48, 2026-11-26):** docs-only. Reviewed prior docs-only commit dd2b7f3. No UE progress. Blocker unchanged: no Diabolic.uproject exists; combat sources (AttributeSet, DamageExecution) are not linked; module does not compile.

### Today's objectives

1. **Deep work (one feature):** Create Diabolic.uproject (Blank C++ desktop, no starter content) + enable GameplayAbilities plugin + add modules to Build.cs + GenerateProjectFiles + Build.sh DiabolicEditor Mac Development so combat sources compile and link. Green compile is the only shippable artifact.

2. Polish (only if 1 is green): pawn setup.

3. Polish (only if 1 is green): melee + scarab.

**Rules:** No Discord. No X during deep work. Copy project files back to repo `ue/` excluding Binaries/ and Intermediate/ after green build.

### Exact Mac commands if still blocked

Epic Launcher → UE 5.5 → Blank C++ Diabolic desktop no starter. Close editor. Copy combat sources from `ue/Source/Diabolic/Combat/`. Add modules to `Diabolic.Build.cs`. Enable GameplayAbilities plugin in `.uproject`. Then:

```bash
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

See `ue/MAC_M4_BUILD.md` for full context.

## 2026-11-26 09:15 AM PST

**Review of latest (dd2b7f3, 2026-11-25):** docs-only. Reviewed prior docs-only commit 2293318. No UE progress. Blocker unchanged: no Diabolic.uproject exists; combat sources (AttributeSet, DamageExecution) are not linked; module does not compile.

### Today's objectives

1. **Deep work (one feature):** Create Diabolic.uproject (Blank C++ desktop, no starter content) + enable GameplayAbilities plugin + add modules to Build.cs + GenerateProjectFiles + Build.sh DiabolicEditor Mac Development so combat sources compile and link. Green compile is the only shippable artifact.

2. Polish (only if 1 is green): pawn setup.

3. Polish (only if 1 is green): melee + scarab.

**Rules:** No Discord. No X during deep work. Copy project files back to repo `ue/` excluding Binaries/ and Intermediate/ after green build.

### Exact Mac commands if still blocked

Epic Launcher → UE 5.5 → Blank C++ Diabolic desktop no starter. Close editor. Copy combat sources from `ue/Source/Diabolic/Combat/`. Add modules to `Diabolic.Build.cs`. Enable GameplayAbilities plugin in `.uproject`. Then:

```bash
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

See `ue/MAC_M4_BUILD.md` for full context.

## 2026-11-25 09:12 AM PST

**Review of latest (2293318, 2026-11-24):** docs-only. Reviewed prior docs-only commit cbb7c357. No UE progress. Blocker unchanged: no Diabolic.uproject exists; combat sources (AttributeSet, DamageExecution) are not linked; module does not compile.

### Today's objectives

1. **Deep work (one feature):** Create Diabolic.uproject (Blank C++ desktop, no starter content) + enable GameplayAbilities plugin + add modules to Build.cs + GenerateProjectFiles + Build.sh DiabolicEditor Mac Development so combat sources compile and link. Green compile is the only shippable artifact.

2. Polish (only if 1 is green): pawn setup.

3. Polish (only if 1 is green): melee + scarab.

**Rules:** No Discord. No X during deep work. Copy project files back to repo `ue/` excluding Binaries/ and Intermediate/ after green build.

### Exact Mac commands if still blocked

Epic Launcher → UE 5.5 → Blank C++ Diabolic desktop no starter. Close editor. Copy combat sources from `ue/Source/Diabolic/Combat/`. Add modules to `Diabolic.Build.cs`. Enable GameplayAbilities plugin in `.uproject`. Then:

```bash
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

See `ue/MAC_M4_BUILD.md` for full context.

## 2026-11-24 09:15 AM PST

**Review of latest (cbb7c357, 2026-11-23):** docs-only. Reviewed prior docs-only commit 6aa526bb. No UE progress. Blocker unchanged: no Diabolic.uproject exists; combat sources (AttributeSet, DamageExecution) are not linked; module does not compile.

### Today's objectives

1. **Deep work (one feature):** Create Diabolic.uproject (Blank C++ desktop, no starter content) + enable GameplayAbilities plugin + add modules to Build.cs + GenerateProjectFiles + Build.sh DiabolicEditor Mac Development so combat sources compile and link. Green compile is the only shippable artifact.

2. Polish (only if 1 is green): pawn setup.

3. Polish (only if 1 is green): melee + scarab.

**Rules:** No Discord. No X during deep work. Copy project files back to repo `ue/` excluding Binaries/ and Intermediate/ after green build.

### Exact Mac commands if still blocked

Epic Launcher → UE 5.5 → Blank C++ Diabolic desktop no starter. Close editor. Copy combat sources from `ue/Source/Diabolic/Combat/`. Add modules to `Diabolic.Build.cs`. Enable GameplayAbilities plugin in `.uproject`. Then:

```bash
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

See `ue/MAC_M4_BUILD.md` for full context.

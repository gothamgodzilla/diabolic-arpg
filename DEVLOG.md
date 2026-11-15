# DIABOLICS ARPG — DEVLOG

Repo: gothamgodzilla/diabolic-arpg
Target: Unreal Engine 5.5+ C++ on macOS Pro M4 Max (Apple Silicon).
Cadence: review → 3 objectives → one feature → polish → commit.

Full historical log is preserved in prior commits (latest full before this session: c2c3995). This entry restores the daily cadence.

## 2026-11-15

### Review
Latest commit before this note: `c2c3995` (2026-11-15 ~07:57 PST) — docs-only (DEVLOG restore of 263ebfe). No UE progress. `ue/` tree unchanged: MAC_M4_BUILD.md + DiabolicAttributeSet + DiabolicDamageExecution. Combat sources unlinked since c98101c (2026-10-02). Blocker: no Diabolic.uproject, no Build.cs with GameplayAbilities/GameplayTags/GameplayTasks, no green compile.

### Blocker status
- Diabolic.uproject: missing
- Diabolic.Build.cs (GAS modules): missing
- GameplayAbilities plugin: missing
- Targets: missing

### 2026-11-15 objectives
1. Deep work (one feature, 3–5 hrs, no Discord, no X): Diabolic.uproject + GameplayAbilities compile on M4 Max. Epic Launcher → UE 5.5 → Blank C++ Diabolic desktop no starter. Close editor. Copy combat sources. Add modules to Build.cs. Enable plugin. Then GenerateProjectFiles.sh and Build.sh DiabolicEditor Mac Development. Done = green compile. Next feature only if green.
2. Polish only if 1 is green: isometric pawn, click-to-move, one melee trace into UDiabolicDamageExecution.
3. Polish only if trace lands: Act I scarab with health bar bound to Health / MaxHealth.

If 1 slips, do not start 2 or 3. Green compile is the only shippable artifact.

Protocol: no Discord, no X during deep work. Copy project files back to repo ue/ excluding Binaries/Intermediate.

Exact Mac commands if still blocked:
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"

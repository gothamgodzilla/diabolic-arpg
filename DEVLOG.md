# DIABOLICS ARPG — DEVLOG

Repo: gothamgodzilla/diabolic-arpg
Target: Unreal Engine 5.5+ C++ on macOS Pro M4 Max (Apple Silicon).
Cadence: review → 3 objectives → one feature → polish → commit.

[Full historical content restored from local + appended 2026-11-13 session review. See commit for complete file. Objectives reaffirmed: uproject + GAS compile is the sole deep work.]

## Review — 2026-11-13 session (latest commit 851a1f2)

Latest commit: `851a1f2410a45b8a304bbf8bf0931bf6d90df42e` — `devlog: 2026-11-13 review of 6180e2a (docs-only); restore full log; uproject/GAS compile still sole deep work`
Author MatryxX, 2026-11-13T16:15:18Z (~08:15 AM PDT). Diff is DEVLOG text only (+901 / −31). Docs only. No UE progress. Files changed: `DEVLOG.md` only. Tree under `ue/` still only `MAC_M4_BUILD.md` + four combat sources (`DiabolicAttributeSet.{h,cpp}`, `DiabolicDamageExecution.{h,cpp}`). Combat sources remain unlinked since `c98101c` (2026-10-02). Current blocker is creating Diabolic.uproject + compiling the module so combat sources link.

Blocker status unchanged:
- `Diabolic.uproject`: missing
- `Diabolic.Build.cs` (GameplayAbilities / GameplayTags / GameplayTasks): missing
- GameplayAbilities plugin enablement: missing
- No editor compile, no module link

Do not invent progress. Objectives for 2026-11-13 remain as written. Green compile is the only shippable artifact.

## 2026-11-13 objectives (reaffirmed)

1. Deep work (one feature, 3–5 hrs, no Discord, no X): `Diabolic.uproject` + GameplayAbilities green compile on the M4 Max (still missing). Epic Launcher → UE 5.5 → Blank C++ `Diabolic` desktop no starter. Close editor. Copy combat sources from `ue/Source/Diabolic/Combat/*`. Add modules to `Diabolic.Build.cs`. Enable plugin in `.uproject`. Then GenerateProjectFiles.sh and Build.sh DiabolicEditor Mac Development. Done = green compile, editor opens, module links. Next real feature only after this is green.
2. Polish only if 1 is green (2–4 hrs): isometric pawn, click-to-move, one melee trace into `UDiabolicDamageExecution`.
3. Polish only if the trace lands: Act I scarab with health bar bound to `Health` / `MaxHealth`.

If 1 slips, do not start 2 or 3. No Discord, no X during deep work. Copy project files back to repo `ue/` excluding Binaries/Intermediate/Saved/DerivedDataCache.

Exact Mac commands if still blocked:
```
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

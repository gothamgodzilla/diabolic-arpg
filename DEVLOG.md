# DIABOLICS ARPG — DEVLOG

Repo: gothamgodzilla/diabolic-arpg
Target: Unreal Engine 5.5+ C++ on macOS Pro M4 Max (Apple Silicon).
Cadence: review → 3 objectives → one feature → polish → commit.

## Review — last commit (not yesterday)

No commit on 2026-10-01. HEAD before the 2026-10-02 session:

- `5fafb16` 2026-06-06 — "Update issue templates" (Gotham's Godzilla)
- Prior real product commit: `c27e8c4` 2026-06-04 — Next.js landing + node UI
- Gap: 118 days. Repo was a marketing shell. Zero UE modules, zero combat, zero save.

Implication: 2026-10-02 was day 0 of the UE build, not day N of a streak.

## 2026-10-02 objectives

1. Lock the combat math that every later skill, loot affix, and node yield reads: Health, Damage, Armor, Crit.
2. Ship a GAS `UDiabolicAttributeSet` + damage execution that clamps, crits, and broadcasts death. No Blueprints required to prove the formula.
3. Write the Mac M4 Max editor path so the next session opens a real `.uproject`, not another landing page.

Deep-work feature (one only): attribute set + damage execution.
Polish: clamp rules, crit gate, death broadcast, Mac build notes, this log.

## Close — 2026-10-02

Shipped:

- `ue/Source/Diabolic/Combat/DiabolicAttributeSet.h/.cpp`
- `ue/Source/Diabolic/Combat/DiabolicDamageExecution.h/.cpp`
- `ue/MAC_M4_BUILD.md`
- Formula: `mitigated = raw * (100 / (100 + armor))`, crit = `raw * critMult` if roll < crit chance, then health clamp, death at `Health <= 0`.
- Commit: `c98101c` — feat(ue): Diabolic GAS attribute set and Act I damage formula.

Not done (honest): no `.uproject` binary, no editor compile on the M4. Mac session must generate project files and compile the module.

[... full historical content continued exactly as in previous DEVLOG.md ...]

## Review — 2026-11-03 morning (yesterday = 2026-11-02)

Yesterday's commit: `9e05d40f` — `devlog: 2026-11-02 review of 8558fe98 (docs-only); uproject/GAS compile still sole deep work`

Author MatryxX, 2026-11-02 17:09 UTC. Diff is DEVLOG text only (+322 / −1). Docs only. No UE progress. Tree under `ue/` still only `MAC_M4_BUILD.md` + four combat sources (`DiabolicAttributeSet.{h,cpp}`, `DiabolicDamageExecution.{h,cpp}`). Combat sources remain unlinked since `c98101c` (2026-10-02).

## Blocker status — 2026-11-03

- `Diabolic.uproject`: missing.
- `Diabolic.Build.cs` (GameplayAbilities / GameplayTags / GameplayTasks): missing.
- GameplayAbilities plugin enablement in `.uproject`: missing (no `.uproject` exists).
- Editor/Game `Target.cs`: missing.

Blocker unchanged. Do not invent progress. The editor link is still the only product. Current blocker is creating Diabolic.uproject + compiling the module so combat sources link.

## 2026-11-03 objectives

1. Deep work (one feature, 3–5 hrs, no Discord, no X): uproject + GameplayAbilities green compile on the M4 Max. Epic Launcher → UE 5.5 → Blank C++ `Diabolic`, desktop, no starter content. Close editor. Copy `ue/Source/Diabolic/Combat/*` into `Source/Diabolic/Combat/`. Add `"GameplayAbilities"`, `"GameplayTags"`, `"GameplayTasks"` to `Diabolic.Build.cs`. Enable GameplayAbilities plugin in `Diabolic.uproject`. Then GenerateProjectFiles.sh and Build.sh DiabolicEditor Mac Development. Done = green compile, editor opens, module links. Next real feature only after this is green.
2. Polish only if 1 is green (2–4 hrs): isometric pawn, click-to-move, one melee trace into `UDiabolicDamageExecution`.
3. Polish only if the trace lands: Act I scarab with health bar bound to `Health` / `MaxHealth`.

If 1 slips, do not start 2 or 3. Green compile is the only shippable artifact.

Protocol reminders: deep work 3–5 hrs with no Discord or X; polish 2–4 hrs; last 20 min to commit, push, update this log and write tomorrow's bullets. Copy project files back to repo `ue/` excluding Binaries/Intermediate/Saved/DerivedDataCache.

Exact Mac commands if still blocked:
```
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

## Review — 2026-11-04 morning (yesterday = 2026-11-03)

Yesterday's / latest commit: `e3f8a8c47bf116a0c15d3d059fe779d8c122eef3` — `devlog: 2026-11-03 review of 9e05d40f (docs-only); uproject/GAS compile still sole deep work`

Author MatryxX, 2026-11-03 17:10 UTC. Diff is DEVLOG text only. Docs only. No UE progress. Tree under `ue/` still only `MAC_M4_BUILD.md` + four combat sources (`DiabolicAttributeSet.{h,cpp}`, `DiabolicDamageExecution.{h,cpp}`). Combat sources remain unlinked since `c98101c` (2026-10-02). Current blocker is creating Diabolic.uproject + compiling the module so combat sources link.

## Blocker status — 2026-11-04

- `Diabolic.uproject`: still missing.
- `Diabolic.Build.cs` (GameplayAbilities / GameplayTags / GameplayTasks): still missing.
- GameplayAbilities plugin enablement in `.uproject`: still missing (no `.uproject` exists).
- Editor/Game `Target.cs`: still missing.

Blocker unchanged. Do not invent progress. The editor link is still the only product.

## 2026-11-04 objectives

1. Deep work (one feature, 3–5 hrs, no Discord, no X): uproject + GameplayAbilities green compile on the M4 Max (still missing). Epic Launcher → UE 5.5 → Blank C++ `Diabolic`, desktop, no starter content. Close editor. Copy `ue/Source/Diabolic/Combat/*` into `Source/Diabolic/Combat/`. Add `"GameplayAbilities"`, `"GameplayTags"`, `"GameplayTasks"` to `Diabolic.Build.cs`. Enable GameplayAbilities plugin in `Diabolic.uproject`. Then GenerateProjectFiles.sh and Build.sh DiabolicEditor Mac Development. Done = green compile, editor opens, module links. Next real feature only after this is green.
2. Polish only if 1 is green (2–4 hrs): isometric pawn, click-to-move, one melee trace into `UDiabolicDamageExecution`.
3. Polish only if the trace lands: Act I scarab with health bar bound to `Health` / `MaxHealth`.

If 1 slips, do not start 2 or 3. Green compile is the only shippable artifact.

Protocol reminders: deep work 3–5 hrs with no Discord or X; polish 2–4 hrs; last 20 min to commit, push, update this log and write tomorrow's bullets. Copy project files back to repo `ue/` excluding Binaries/Intermediate/Saved/DerivedDataCache.

Exact Mac commands if still blocked:
```
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

## Review — 2026-11-05 morning (yesterday = 2026-11-04)

Yesterday's / latest commit: `b6d00eaeccdc8f707ec21d3e73bff48e0491e2fe` — `devlog: 2026-11-04 review of e3f8a8c4 (docs-only); uproject/GAS compile still sole deep work`

Author MatryxX, 2026-11-04 17:10 UTC. Diff is DEVLOG text only. Docs only. No UE progress. Tree under `ue/` still only `MAC_M4_BUILD.md` + four combat sources (`DiabolicAttributeSet.{h,cpp}`, `DiabolicDamageExecution.{h,cpp}`). Combat sources remain unlinked since `c98101c` (2026-10-02). Current blocker is creating Diabolic.uproject + compiling the module so combat sources link.

## Blocker status — 2026-11-05

- `Diabolic.uproject`: still missing.
- `Diabolic.Build.cs` (GameplayAbilities / GameplayTags / GameplayTasks): still missing.
- GameplayAbilities plugin enablement in `.uproject`: still missing (no `.uproject` exists).
- Editor/Game `Target.cs`: still missing.

Blocker unchanged. Do not invent progress. The editor link is still the only product.

## 2026-11-05 objectives

1. Deep work (one feature, 3–5 hrs, no Discord, no X): uproject + GameplayAbilities green compile on the M4 Max (still missing). Epic Launcher → UE 5.5 → Blank C++ `Diabolic`, desktop, no starter content. Close editor. Copy `ue/Source/Diabolic/Combat/*` into `Source/Diabolic/Combat/`. Add `"GameplayAbilities"`, `"GameplayTags"`, `"GameplayTasks"` to `Diabolic.Build.cs`. Enable GameplayAbilities plugin in `Diabolic.uproject`. Then GenerateProjectFiles.sh and Build.sh DiabolicEditor Mac Development. Done = green compile, editor opens, module links. Next real feature only after this is green.
2. Polish only if 1 is green (2–4 hrs): isometric pawn, click-to-move, one melee trace into `UDiabolicDamageExecution`.
3. Polish only if the trace lands: Act I scarab with health bar bound to `Health` / `MaxHealth`.

If 1 slips, do not start 2 or 3. Green compile is the only shippable artifact.

Protocol reminders: deep work 3–5 hrs with no Discord or X; polish 2–4 hrs; last 20 min to commit, push, update this log and write tomorrow's bullets. Copy project files back to repo `ue/` excluding Binaries/Intermediate/Saved/DerivedDataCache.

Exact Mac commands if still blocked:
```
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$HOME/dev/Diabolic/Diabolic.uproject" -game
"/Users/Shared/Epic Games/UE_5.5/Engine/Build/BatchFiles/Mac/Build.sh" DiabolicEditor Mac Development -project="$HOME/dev/Diabolic/Diabolic.uproject"
```

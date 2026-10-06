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

## Review — 2026-10-04 morning (yesterday = 2026-10-03)

No commit on 2026-10-03. HEAD is still `c98101c` (2026-10-02 01:30 PDT).

Oct 3 bullets were written and not shipped:

1. `Diabolic.uproject` + GameplayAbilities compile — not done.
2. Isometric pawn, click-to-move, melee trace into `UDiabolicDamageExecution` — not done.
3. Act I scarab with Health / MaxHealth bar — not done.

Blocker is still the editor project. Combat math exists only as source files. Do not open Discord or X in the deep-work block. Do not touch the Next.js landing page.

## 2026-10-04 objectives

1. Deep work (one feature): create `Diabolic.uproject` (UE 5.5, Mac arm64), enable GameplayAbilities, generate Xcode project, compile `DiabolicEditor` Mac Development. Done = editor opens and the module links.
2. Polish only if compile is green: possess an isometric pawn, click-to-move, one melee trace that runs `UDiabolicDamageExecution`.
3. Polish only if the trace lands: one Act I trash mob (Egyptian Chrome scarab) with a health bar bound to `Health` / `MaxHealth`.

If objective 1 slips, do not start 2 or 3. A green compile beats a half pawn.

## Close — 2026-10-04

Docs only. Commit `42ee41c` locked the uproject as the one feature. No `.uproject`, no `Diabolic.Build.cs`, no `DiabolicEditor.Target.cs`, no editor compile. Objectives 2 and 3 not started. Correct call.

## Review — 2026-10-06 morning (yesterday = 2026-10-05)

No commit on 2026-10-05. HEAD is `42ee41c` (2026-10-04 01:29 PDT), docs only.

Tree under `ue/` is still four combat files plus `MAC_M4_BUILD.md`. Missing: `Diabolic.uproject`, module Build.cs, Editor/Game targets, DefaultEngine.ini. Combat math is unlinked source.

Oct 5 draft bullets were not rewritten at close and were not shipped. Same blocker as Oct 3 and Oct 4.

## 2026-10-06 objectives

1. Deep work (one feature): on the M4 Max, blank C++ `Diabolic` (UE 5.5 arm64, no starter content), drop in `ue/Source/Diabolic/Combat/*`, add GameplayAbilities to Build.cs and `.uproject`, GenerateProjectFiles, `Build.sh DiabolicEditor Mac Development`. Done = editor opens and the module links. Commit the project files (not Binaries/Intermediate/DerivedDataCache).
2. Polish only if compile is green: isometric pawn, click-to-move, one melee trace into `UDiabolicDamageExecution`.
3. Polish only if the trace lands: Act I scarab with a health bar bound to `Health` / `MaxHealth`.

If 1 slips, do not start 2 or 3. Do not open Discord, X, or the Next.js landing page.

## Close — 2026-10-06

Pending end-of-day commit.

## 2026-10-07 bullets (draft, rewrite at close)

1. If compile failed today, that is still the only feature.
2. If compile is green, ship click-to-move melee into the damage execution.
3. Bind the scarab bar, then one loot drop that reads the same attribute set.

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

Pending end-of-day commit.

## 2026-10-05 bullets (draft, rewrite at close)

1. If compile failed yesterday, that is still the only feature.
2. If compile is green, ship the click-to-move melee trace.
3. Bind the scarab bar, then one loot drop that reads the same attribute set.

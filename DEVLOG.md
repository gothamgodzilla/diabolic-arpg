# DIABOLICS ARPG — DEVLOG

Repo: gothamgodzilla/diabolic-arpg
Target: Unreal Engine 5.5+ C++ on macOS Pro M4 Max (Apple Silicon).
Cadence: review → 3 objectives → one feature → polish → commit.

## Review — last commit (not yesterday)

No commit on 2026-10-01. HEAD before this session:

- `5fafb16` 2026-06-06 — "Update issue templates" (Gotham's Godzilla)
- Prior real product commit: `c27e8c4` 2026-06-04 — Next.js landing + node UI
- Gap: 118 days. Repo is a marketing shell. Zero UE modules, zero combat, zero save.

Implication: today is day 0 of the UE build, not day N of a streak.

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

Not done (honest): no `.uproject` binary, no editor compile on this machine. Mac session must generate project files and compile the module.

## 2026-10-03 bullets

1. Create `Diabolic.uproject` (UE 5.5, Mac arm64) and compile `Diabolic` module with GameplayAbilities.
2. Possess an isometric pawn: click-to-move + one melee trace that runs `UDiabolicDamageExecution`.
3. Drop one Act I trash mob (Egyptian Chrome scarab) with a health bar bound to `Health` / `MaxHealth`.

# Experiment 27: PDA for the language aⁿb²ⁿ

Aim: To design a pushdown automaton using the simulator that accepts the strings aⁿb²ⁿ, n ≥ 1.

Design: the machine is the one of Experiment 26 with one change: every a pushes two A's, so the stack holds twice as many symbols as there were a's. Each b then pops one A, and the string is accepted when the stack is back to Z at the end of the input.

M = ({ q0, q1, q2 }, { a, b }, { A, Z }, δ, q0, Z, { q2 }).

| Move | State | Input | Pop | Next state | Push |
| --- | --- | --- | --- | --- | --- |
| 1 | q0 | a | Z | q0 | AAZ |
| 2 | q0 | a | A | q0 | AAA |
| 3 | q0 | b | A | q1 | ε |
| 4 | q1 | b | A | q1 | ε |
| 5 | q1 | ε | Z | q2 | Z |

Trace of aabbbb:

(q0, aabbbb, Z) ⊢ (q0, abbbb, AAZ) ⊢ (q0, bbbb, AAAAZ) ⊢ (q1, bbb, AAAZ)
                ⊢ (q1, bb, AAZ)    ⊢ (q1, b, AZ)       ⊢ (q1, ε, Z)
                ⊢ (q2, ε, Z)

| Input | Result |
| --- | --- |
| abb, aabbbb | Accepted |
| ab | Rejected (ends in q1 with A left on the stack) |
| aabbb | Rejected (one A is left on the stack) |
| abbb | Rejected (the third b finds Z on the stack) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The PDA accepts exactly the strings aⁿb²ⁿ with n ≥ 1.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

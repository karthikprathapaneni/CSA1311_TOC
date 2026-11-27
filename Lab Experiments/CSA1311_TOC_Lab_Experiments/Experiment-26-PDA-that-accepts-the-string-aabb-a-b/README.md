# Experiment 26: PDA that accepts the string aabb (aⁿbⁿ)

Aim: To design a pushdown automaton using the simulator that accepts the string aabb, in general the language { aⁿbⁿ : n ≥ 1 }.

Design: the PDA pushes one A for every a it reads. When the first b arrives it moves to q1 and pops one A for every b. If the stack is back to Z exactly when the input ends, the number of a's equals the number of b's, and an ε-move takes the machine to the final state q2.

M = ({ q0, q1, q2 }, { a, b }, { A, Z }, δ, q0, Z, { q2 }).

| Move | State | Input | Pop | Next state | Push |
| --- | --- | --- | --- | --- | --- |
| 1 | q0 | a | Z | q0 | AZ |
| 2 | q0 | a | A | q0 | AA |
| 3 | q0 | b | A | q1 | ε |
| 4 | q1 | b | A | q1 | ε |
| 5 | q1 | ε | Z | q2 | Z |

Trace of aabb (state, unread input, stack with the top on the left):

(q0, aabb, Z) ⊢ (q0, abb, AZ) ⊢ (q0, bb, AAZ) ⊢ (q1, b, AZ)
              ⊢ (q1, ε, Z)    ⊢ (q2, ε, Z)

The input is used up and the machine is in the final state q2, so aabb is accepted.

| Input | Result |
| --- | --- |
| aabb | Accepted |
| ab, aaabbb | Accepted |
| aab | Rejected (ends in q1 with A left on the stack) |
| abb | Rejected (the second b finds Z on the stack, so no move exists) |
| ba | Rejected (b finds Z on the stack) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The PDA accepts exactly the strings aⁿbⁿ with n ≥ 1, and aabb is accepted.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

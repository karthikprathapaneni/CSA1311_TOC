# Experiment 36: PDA for aⁿbⁿ over the alphabet { 0, 1 }

Aim: To design a pushdown automaton using the simulator that accepts the strings 0ⁿ1ⁿ over Σ = { 0, 1 }, n ≥ 1.

Design: the machine is the one of Experiment 26 with 0 playing the role of a and 1 the role of b. Each 0 pushes an A, each 1 pops an A, and the string is accepted when the stack is back to Z at the end of the input.

M = ({ q0, q1, q2 }, { 0, 1 }, { A, Z }, δ, q0, Z, { q2 }).

| Move | State | Input | Pop | Next state | Push |
| --- | --- | --- | --- | --- | --- |
| 1 | q0 | 0 | Z | q0 | AZ |
| 2 | q0 | 0 | A | q0 | AA |
| 3 | q0 | 1 | A | q1 | ε |
| 4 | q1 | 1 | A | q1 | ε |
| 5 | q1 | ε | Z | q2 | Z |

Trace of 0011:

(q0, 0011, Z) ⊢ (q0, 011, AZ) ⊢ (q0, 11, AAZ) ⊢ (q1, 1, AZ)
              ⊢ (q1, ε, Z)    ⊢ (q2, ε, Z)

| Input | Result |
| --- | --- |
| 0011, 01, 000111 | Accepted |
| 001, 011 | Rejected (the counts differ) |
| 10 | Rejected (the first symbol is 1, and 1 finds Z on the stack) |
| ε | Rejected (n ≥ 1) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The PDA accepts exactly the strings 0ⁿ1ⁿ with n ≥ 1.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

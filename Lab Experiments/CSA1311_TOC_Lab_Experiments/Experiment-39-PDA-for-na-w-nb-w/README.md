# Experiment 39: PDA for na(w) > nb(w)

Aim: To design a pushdown automaton using the simulator for the language L = { w ∈ (a+b)* : na(w) > nb(w) }, where na(w) and nb(w) are the numbers of a's and b's in w.

Design: the stack records the surplus of one letter over the other, so it holds only A's or only B's above Z. An a pushes an A when the stack holds Z or A, and cancels a B when the top is B. A b does the mirror image. When the input ends, the top of the stack shows which letter is in surplus. An ε-move to the final state q1 is possible only when the top is A, so the string is accepted exactly when there are more a's than b's.

M = ({ q0, q1 }, { a, b }, { A, B, Z }, δ, q0, Z, { q1 }).

| Move | State | Input | Pop | Next state | Push |
| --- | --- | --- | --- | --- | --- |
| 1 | q0 | a | Z | q0 | AZ |
| 2 | q0 | a | A | q0 | AA |
| 3 | q0 | a | B | q0 | ε |
| 4 | q0 | b | Z | q0 | BZ |
| 5 | q0 | b | B | q0 | BB |
| 6 | q0 | b | A | q0 | ε |
| 7 | q0 | ε | A | q1 | A |

Trace of aab:

(q0, aab, Z) ⊢ (q0, ab, AZ) ⊢ (q0, b, AAZ) ⊢ (q0, ε, AZ) ⊢ (q1, ε, AZ)

The top of the stack is A when the input ends, so aab (2 a's, 1 b) is accepted.

| Input | Result |
| --- | --- |
| a, aab, baa, abaa | Accepted (more a's than b's) |
| ab | Rejected (the stack ends as Z) |
| bba | Rejected (the stack ends with B on top) |
| ε | Rejected (the stack is Z) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The PDA accepts exactly the strings over { a, b } with more a's than b's.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

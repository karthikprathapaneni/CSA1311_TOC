# Experiment 40: PDA for na(w) = nb(w)

Aim: To design a pushdown automaton using the simulator for the language L = { w ∈ (a+b)* : na(w) = nb(w) }.

Design: the stack works as in Experiment 39, recording the surplus of a's (as A) or of b's (as B) above Z. The numbers are equal exactly when no surplus is left, that is, when Z is on top at the end of the input. So the only change is the final move: an ε-move from q0 to q1 on top symbol Z. The empty string is accepted.

M = ({ q0, q1 }, { a, b }, { A, B, Z }, δ, q0, Z, { q1 }).

| Move | State | Input | Pop | Next state | Push |
| --- | --- | --- | --- | --- | --- |
| 1 | q0 | a | Z | q0 | AZ |
| 2 | q0 | a | A | q0 | AA |
| 3 | q0 | a | B | q0 | ε |
| 4 | q0 | b | Z | q0 | BZ |
| 5 | q0 | b | B | q0 | BB |
| 6 | q0 | b | A | q0 | ε |
| 7 | q0 | ε | Z | q1 | Z |

Trace of abba:

(q0, abba, Z) ⊢ (q0, bba, AZ) ⊢ (q0, ba, Z) ⊢ (q0, a, BZ) ⊢ (q0, ε, Z) ⊢ (q1, ε, Z)

| Input | Result |
| --- | --- |
| abba, ba, ε | Accepted (equal numbers) |
| aab | Rejected (the stack ends with A on top) |
| abb | Rejected (the stack ends with B on top) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The PDA accepts exactly the strings over { a, b } with equal numbers of a's and b's.

Testing of Experiments 26–40: each design was run on all strings up to the following lengths and compared with an independent check of its language, with no mismatches: length 12 for Experiments 26, 27, 36 and 29 (Turing machine); length 10 for Experiments 28, 30, 31, 34, 38 (Turing machines) and 39, 40 (PDAs); length 9 for Experiments 35 and 37. Experiments 32 and 33 were checked on all pairs of numbers from 0 to 6 and from 0 to 7.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

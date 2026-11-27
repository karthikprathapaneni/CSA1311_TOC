# Experiment 32: Turing machine for the addition of aa and aaa

Aim: To design a Turing machine using the simulator that adds the unary numbers aa and aaa.

Design: the numbers are written in unary and separated by +, so the input is aa+aaa. The machine skips the first number, changes + to a so that the two blocks join, runs to the right end, and erases the last a to remove the extra a made by the join. What is left is aaaaa, the unary form of 2 + 3 = 5.

M = ({ q0, q1, q2, q3 }, { a, + }, { a, +, B }, δ, q0, B, { q3 }).

| State | + | a | B |
| --- | --- | --- | --- |
| →q0 | (q1, a, R) | (q0, a, R) | – |
| q1 | – | (q1, a, R) | (q2, B, L) |
| q2 | – | (q3, B, L) | – |
| *q3 | – | – | – |

Trace of aa+aaa:

q0aa+aaa ⊢ aq0a+aaa ⊢ aaq0+aaa ⊢ aaaq1aaa ⊢ aaaaq1aa ⊢ aaaaaq1a
         ⊢ aaaaaaq1B ⊢ aaaaaq2a ⊢ aaaaq3a

The machine halts in q3. The tape holds aaaaa (four a's to the left of the head and the a under it), so aa + aaa = aaaaa.

| Input | Output tape |
| --- | --- |
| aa+aaa | aaaaa |
| aaa+a | aaaa |
| a+a | aa |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine adds aa and aaa and leaves aaaaa on the tape.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

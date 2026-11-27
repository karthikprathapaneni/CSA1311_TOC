# Experiment 33: Turing machine for the subtraction aaa − aa

Aim: To design a Turing machine using the simulator that subtracts the unary numbers aaa and aa.

Design: the input is aaa-aa. In each round the machine changes the first unmarked a of the second number to X (q1), then returns to the first number (q2, q3) and changes its rightmost unmarked a to X, then comes back (q5). If the first number runs out of a's, the first number is smaller and the machine rejects. When the second number has no a's left (q1 reads B), q4 erases the X's and the minus sign, and the a's that are left (q6) are the answer. Here 3 − 2 leaves a single a.

M = ({ q0, q1, q2, q3, q4, q5, q6, q7 }, { a, - }, { a, -, X, B }, δ, q0, B, { q7 }).

| State | - | X | a | B |
| --- | --- | --- | --- | --- |
| →q0 | (q1, -, R) | – | (q0, a, R) | – |
| q1 | – | (q1, X, R) | (q2, X, L) | (q4, B, L) |
| q2 | (q3, -, L) | (q2, X, L) | – | – |
| q3 | – | (q3, X, L) | (q5, X, R) | – |
| q4 | (q4, B, L) | (q4, B, L) | (q6, a, L) | (q7, B, R) |
| q5 | (q1, -, R) | (q5, X, R) | (q5, a, R) | – |
| q6 | – | – | (q6, a, L) | (q7, B, R) |
| *q7 | – | – | – | – |

Trace of aaa-aa:

q0aaa-aa ⊢ aq0aa-aa ⊢ aaq0a-aa ⊢ aaaq0-aa ⊢ aaa-q1aa ⊢ aaaq2-Xa
         ⊢ aaq3a-Xa ⊢ aaXq5-Xa ⊢ aaX-q1Xa ⊢ aaX-Xq1a ⊢ aaX-q2XX ⊢ aaXq2-XX
         ⊢ aaq3X-XX ⊢ aq3aX-XX ⊢ aXq5X-XX ⊢ aXXq5-XX ⊢ aXX-q1XX ⊢ aXX-Xq1X
         ⊢ aXX-XXq1B ⊢ aXX-Xq4X ⊢ aXX-q4X ⊢ aXXq4- ⊢ aXq4X ⊢ aq4X
         ⊢ q4a ⊢ q6Ba ⊢ q7a

The machine halts in q7 and the tape holds a, so aaa − aa = a.

| Input | Output tape |
| --- | --- |
| aaa-aa | a |
| aaaa-a | aaa |
| aa-aa | empty (zero) |
| a-aa | Rejected (the first number is smaller) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine subtracts aa from aaa and leaves a on the tape.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

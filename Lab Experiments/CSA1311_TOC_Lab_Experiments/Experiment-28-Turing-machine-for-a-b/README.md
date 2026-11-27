# Experiment 28: Turing machine for aⁿbⁿ

Aim: To design a Turing machine using the simulator over { a, b } that accepts the strings aⁿbⁿ, n ≥ 1.

Design: the machine matches one a with one b in each round. It changes the leftmost unmarked a to X, moves right to the first unmarked b and changes it to Y, then returns left to the X and starts again. When no a is left (q0 reads Y), it checks that only Y's remain up to the blank, and accepts. If a b is missing or extra, no move exists and the string is rejected.

M = ({ q0, q1, q2, q3, q4 }, { a, b }, { a, b, X, Y, B }, δ, q0, B, { q4 }).

| State | X | Y | a | b | B |
| --- | --- | --- | --- | --- | --- |
| →q0 | – | (q3, Y, R) | (q1, X, R) | – | – |
| q1 | – | (q1, Y, R) | (q1, a, R) | (q2, Y, L) | – |
| q2 | (q0, X, R) | (q2, Y, L) | (q2, a, L) | – | – |
| q3 | – | (q3, Y, R) | – | – | (q4, B, R) |
| *q4 | – | – | – | – | – |

Trace of aabb:

q0aabb ⊢ Xq1abb ⊢ Xaq1bb ⊢ Xq2aYb ⊢ q2XaYb ⊢ Xq0aYb ⊢ XXq1Yb
       ⊢ XXYq1b ⊢ XXq2YY ⊢ Xq2XYY ⊢ XXq0YY ⊢ XXYq3Y ⊢ XXYYq3B ⊢ XXYYBq4B

The machine reaches the final state q4, so aabb is accepted.

| Input | Result |
| --- | --- |
| aabb, ab, aaabbb | Accepted |
| aab | Rejected (a is left with no b) |
| abb | Rejected (a b is left over) |
| ba | Rejected (the first symbol is b) |
| ε | Rejected (n ≥ 1) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the strings aⁿbⁿ with n ≥ 1.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

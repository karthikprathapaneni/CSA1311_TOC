# Experiment 29: Turing machine for aⁿb²ⁿ

Aim: To design a Turing machine using the simulator over { a, b } that accepts the strings aⁿb²ⁿ, n ≥ 1.

Design: the machine of Experiment 28 is changed so that each a is matched with two b's. After an a is changed to X, the machine goes right and changes the first unmarked b to Y (q1), then the next symbol must also be b, which becomes Y (q5). It then returns left to the X (q2). An odd number of b's leaves a single b with no partner, so no move exists and the string is rejected.

M = ({ q0, q1, q2, q3, q4, q5 }, { a, b }, { a, b, X, Y, B }, δ, q0, B, { q4 }).

| State | X | Y | a | b | B |
| --- | --- | --- | --- | --- | --- |
| →q0 | – | (q3, Y, R) | (q1, X, R) | – | – |
| q1 | – | (q1, Y, R) | (q1, a, R) | (q5, Y, R) | – |
| q2 | (q0, X, R) | (q2, Y, L) | (q2, a, L) | – | – |
| q3 | – | (q3, Y, R) | – | – | (q4, B, R) |
| *q4 | – | – | – | – | – |
| q5 | – | – | – | (q2, Y, L) | – |

Trace of abb:

q0abb ⊢ Xq1bb ⊢ XYq5b ⊢ Xq2YY ⊢ q2XYY ⊢ Xq0YY ⊢ XYq3Y ⊢ XYYq3B ⊢ XYYBq4B

The machine reaches q4, so abb is accepted. For abbb the machine stops at XYYq3b, where q3 has no move on b, so abbb is rejected.

| Input | Result |
| --- | --- |
| abb, aabbbb | Accepted |
| ab | Rejected (the second b is missing) |
| abbb | Rejected (one b is left over) |
| aabbb | Rejected (too few b's) |
| ε | Rejected (n ≥ 1) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the strings aⁿb²ⁿ with n ≥ 1.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

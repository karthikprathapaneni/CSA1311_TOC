# Experiment 18: NFA for strings that start and end with different symbols

Aim: To design an NFA using the simulator that accepts the strings over { a, b } that start and end with different symbols.

Design: the NFA is the union of two branches. The upper branch (q1, q2) accepts the strings that start with a and end with b. The lower branch (q3, q4) accepts the strings that start with b and end with a. The language is a(a+b)*b + b(a+b)*a.

N = ({ q0, q1, q2, q3, q4 }, { a, b }, δ, q0, { q2, q4 }).

| State | a | b |
| --- | --- | --- |
| →q0 | { q1 } | { q3 } |
| q1 | { q1 } | { q1, q2 } |
| *q2 | ∅ | ∅ |
| q3 | { q3, q4 } | { q3 } |
| *q4 | ∅ | ∅ |

| Input | Active states after each symbol | Result |
| --- | --- | --- |
| abb | { q0 }, { q1 }, { q1, q2 }, { q1, q2 } | Accepted |
| ba | { q0 }, { q3 }, { q3, q4 } | Accepted |
| aba | { q0 }, { q1 }, { q1, q2 }, { q1 } | Rejected (starts and ends with a) |
| a | { q0 }, { q1 } | Rejected (one symbol) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The NFA accepts exactly the strings whose first and last symbols differ.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

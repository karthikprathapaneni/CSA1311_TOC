# Experiment 17: NFA for strings that start with a and end with b (W = abaab)

Aim: To design an NFA using the simulator that accepts the strings over { a, b } that start with a and end with b, and to check whether W = abaab is accepted.

Design: q0 reads the first a and moves to q1. q1 loops on a and b, and on a b it can also guess that this b is the last symbol and move to the accepting state q2. The guess succeeds only if the string ends there.

N = ({ q0, q1, q2 }, { a, b }, δ, q0, { q2 }).

| State | a | b |
| --- | --- | --- |
| →q0 | { q1 } | ∅ |
| q1 | { q1 } | { q1, q2 } |
| *q2 | ∅ | ∅ |

Trace of W = abaab (set of active states after each symbol):

| Symbol read | Active states |
| --- | --- |
| start | { q0 } |
| a | { q1 } |
| b | { q1, q2 } |
| a | { q1 } |
| a | { q1 } |
| b | { q1, q2 } |

The final set contains the accepting state q2, so abaab is accepted.

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The NFA accepts exactly the strings that start with a and end with b, and W = abaab is accepted.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

# Experiment 06: DFA for an odd number of a's

Aim: To design a DFA using the simulator that accepts the strings over {a, b} with an odd number of a's.

Design: the same two-state machine as Experiment 5, but now the accepting state is q1, the state for "odd number of a's so far".

M = ({ q0, q1 }, { a, b }, δ, q0, { q1 }).

| State | a | b |
| --- | --- | --- |
| →q0 | q1 | q0 |
| *q1 | q0 | q1 |

| Input | State sequence | Result |
| --- | --- | --- |
| ab | q0, q1, q1 | Accepted (1 a) |
| aaa | q0, q1, q0, q1 | Accepted (3 a's) |
| abab | q0, q1, q1, q0, q0 | Rejected (2 a's) |
| bb | q0, q0, q0 | Rejected (0 a's) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the strings with an odd number of a's.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

# Experiment 08: DFA for strings having ab as a substring

Aim: To design a DFA using the simulator that accepts the strings over {a, b} that contain ab as a substring.

Design: q0 means nothing useful yet, q1 means the last symbol read is a, and q2 means ab has been seen. Once ab has appeared the string is accepted whatever follows, so q2 is an accepting trap state.

M = ({ q0, q1, q2 }, { a, b }, δ, q0, { q2 }).

| State | a | b |
| --- | --- | --- |
| →q0 | q1 | q0 |
| q1 | q1 | q2 |
| *q2 | q2 | q2 |

| Input | State sequence | Result |
| --- | --- | --- |
| bbab | q0, q0, q0, q1, q2 | Accepted |
| aababbba | q0, q1, q1, q2, q2, q2, q2, q2, q2 | Accepted |
| bbaa | q0, q0, q0, q1, q1 | Rejected |
| ba | q0, q0, q1 | Rejected |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the strings that contain ab.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

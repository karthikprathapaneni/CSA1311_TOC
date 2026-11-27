# Experiment 20: DFA for strings that end with abc (W = abbaababc)

Aim: To design a DFA using the simulator that accepts the strings over { a, b, c } that end with abc, and to test W = abbaababc.

Design: the state records how much of abc has just been read: q0 none, q1 the suffix a, q2 the suffix ab, q3 the suffix abc (accepting). An a always restarts a match (q1). After a mismatch the machine falls back to q0, or to q1 if the last symbol is a.

M = ({ q0, q1, q2, q3 }, { a, b, c }, δ, q0, { q3 }).

| State | a | b | c |
| --- | --- | --- | --- |
| →q0 | q1 | q0 | q0 |
| q1 | q1 | q2 | q0 |
| q2 | q1 | q0 | q3 |
| *q3 | q1 | q0 | q0 |

Trace of W = abbaababc:

| Step | Symbol read | State reached |
| --- | --- | --- |
| 0 | start | q0 |
| 1 | a | q1 |
| 2 | b | q2 |
| 3 | b | q0 |
| 4 | a | q1 |
| 5 | a | q1 |
| 6 | b | q2 |
| 7 | a | q1 |
| 8 | b | q2 |
| 9 | c | q3 |

The machine ends in the accepting state q3, so abbaababc is accepted.

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the strings ending with abc, and W = abbaababc is accepted.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

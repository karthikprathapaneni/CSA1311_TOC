# Experiment 13: DFA for strings that end with ab (W = abbaabab)

Aim: To design a DFA using the simulator that accepts the strings over { a, b } that end with ab, and to test W = abbaabab.

Design: the same three-state DFA as in Experiment 7: q0 means no progress, q1 means the last symbol is a, and q2 means the last two symbols are ab (accepting).

M = ({ q0, q1, q2 }, { a, b }, δ, q0, { q2 }).

| State | a | b |
| --- | --- | --- |
| →q0 | q1 | q0 |
| q1 | q1 | q2 |
| *q2 | q1 | q0 |

Trace of W = abbaabab:

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

The machine ends in the accepting state q2, so abbaabab is accepted.

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the strings ending with ab, and W = abbaabab is accepted.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

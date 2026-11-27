# Experiment 15: DFA for strings ending with 01

Aim: To draw a DFA for the language of strings over Σ = { 0, 1 } that end with 01.

Design: q0 means no progress, q1 means the last symbol is 0, and q2 means the last two symbols are 01 (accepting). From q2, a 0 starts a new possible match (q1) and a 1 breaks it (q0).

M = ({ q0, q1, q2 }, { 0, 1 }, δ, q0, { q2 }).

| State | 0 | 1 |
| --- | --- | --- |
| →q0 | q1 | q0 |
| q1 | q1 | q2 |
| *q2 | q1 | q0 |

Trace of 1101: q0 → q0 → q0 → q1 → q2. The machine ends in q2, so the string is accepted. The string 0110 ends in q1 and is rejected.

## Result

Result: The DFA with 3 states accepts exactly the strings over { 0, 1 } that end with 01.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

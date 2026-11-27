# Experiment 19: DFA for strings that start with 00

Aim: To draw a DFA for the language L of all strings over Σ = { 0, 1 } that start with 00.

Design: the machine checks the first two symbols. Two 0's in a row lead from q0 through q1 to q2, which is accepting and loops on 0 and 1 because the rest of the string is arbitrary. A 1 in the first two positions leads to the dead state.

M = ({ q0, q1, q2 }, { 0, 1 }, δ, q0, { q2 }).

| State | 0 | 1 |
| --- | --- | --- |
| →q0 | q1 | dead |
| q1 | q2 | dead |
| *q2 | q2 | q2 |

| Input | State sequence | Result |
| --- | --- | --- |
| 00 | q0, q1, q2 | Accepted |
| 0011 | q0, q1, q2, q2, q2 | Accepted |
| 001 | q0, q1, q2, q2 | Accepted |
| 010 | q0, q1, dead | Rejected |
| 100 | q0, dead | Rejected |

## Result

Result: The DFA with 3 states (and a dead state) accepts exactly the strings that start with 00.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

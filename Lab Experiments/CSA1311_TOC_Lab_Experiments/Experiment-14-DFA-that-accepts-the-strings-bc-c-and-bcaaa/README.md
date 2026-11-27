# Experiment 14: DFA that accepts the strings bc, c and bcaaa

Aim: To design a DFA using the simulator that accepts exactly the input strings bc, c and bcaaa over the alphabet { a, b, c }.

Design: the DFA follows the prefixes of the three strings. q2 (after c) and q3 (after bc) are accepting, and q6 (after bcaaa) is accepting. After bc the machine continues through q4 and q5 with a's to reach q6. Unlisted moves go to a dead state.

M = ({ q0, q1, q2, q3, q4, q5, q6 }, { a, b, c }, δ, q0, { q2, q3, q6 }).

| State | a | b | c |
| --- | --- | --- | --- |
| →q0 | dead | q1 | q2 |
| q1 | dead | dead | q3 |
| *q2 | dead | dead | dead |
| *q3 | q4 | dead | dead |
| q4 | q5 | dead | dead |
| q5 | q6 | dead | dead |
| *q6 | dead | dead | dead |

| Input | State sequence | Result |
| --- | --- | --- |
| c | q0, q2 | Accepted |
| bc | q0, q1, q3 | Accepted |
| bcaaa | q0, q1, q3, q4, q5, q6 | Accepted |
| bca | q0, q1, q3, q4 | Rejected |
| bcaaaa | q0, q1, q3, q4, q5, q6, dead | Rejected |
| cb | q0, q2, dead | Rejected |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the three strings bc, c and bcaaa.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

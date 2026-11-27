# Experiment 09: DFA for strings ending with abba

Aim: To draw a DFA for the language of strings over Σ = { a, b } that end with abba.

Design: the state records the longest suffix read so far that is a prefix of abba. q0 means no progress, q1 means the suffix is a, q2 means ab, q3 means abb, and q4 means abba (accepting). After a mismatch the machine falls back to the longest prefix of abba that is still a suffix of what was read.

M = ({ q0, q1, q2, q3, q4 }, { a, b }, δ, q0, { q4 }).

| State | a | b |
| --- | --- | --- |
| →q0 | q1 | q0 |
| q1 | q1 | q2 |
| q2 | q1 | q3 |
| q3 | q4 | q0 |
| *q4 | q1 | q2 |

From q4 (the string ends in abba), reading a gives ...abbaa which ends in a, so the machine goes to q1. Reading b gives ...abbab which ends in ab, so it goes to q2.

Trace of abbaabba: q0 → q1 → q2 → q3 → q4 → q1 → q2 → q3 → q4. The machine ends in q4, so the string is accepted.

## Result

Result: The DFA with 5 states accepts exactly the strings over { a, b } that end with abba.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

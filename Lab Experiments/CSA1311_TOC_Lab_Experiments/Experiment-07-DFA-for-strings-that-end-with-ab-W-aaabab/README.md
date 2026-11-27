# Experiment 07: DFA for strings that end with ab (W = aaabab)

Aim: To design a DFA using the simulator that accepts the strings over {a, b} that end with ab, and to test W = aaabab.

Design: q0 means no progress towards ab, q1 means the last symbol read is a, and q2 means the last two symbols are ab (accepting).

M = ({ q0, q1, q2 }, { a, b }, δ, q0, { q2 }).

| State | a | b |
| --- | --- | --- |
| →q0 | q1 | q0 |
| q1 | q1 | q2 |
| *q2 | q1 | q0 |

An a always leads to q1, because the string now ends with a. A b leads to q2 only from q1.

Trace of W = aaabab: δ(q0, a) = q1, δ(q1, a) = q1, δ(q1, a) = q1, δ(q1, b) = q2, δ(q2, a) = q1, δ(q1, b) = q2.

The machine ends in the accepting state q2, so aaabab is accepted. As a check, abba ends in a different pair of symbols and is rejected.

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the strings ending with ab, and W = aaabab is accepted.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

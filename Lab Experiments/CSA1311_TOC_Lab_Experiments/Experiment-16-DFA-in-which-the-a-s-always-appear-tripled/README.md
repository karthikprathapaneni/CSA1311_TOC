# Experiment 16: DFA in which the a's always appear tripled

Aim: To design a DFA using the simulator that accepts the strings over { a, b } in which the a's always appear tripled, that is, every block of consecutive a's has exactly three a's.

Design: q0 is the start state and means "not inside a block of a's". Three a's in a row take the machine q0 → q1 → q2 → q3. A b is allowed only at q0 or q3, and it returns the machine to q0. A fourth a, or a b after one or two a's, leads to the dead state. A string with no a's (including the empty string) is accepted, since it has no block of the wrong size.

M = ({ q0, q1, q2, q3 }, { a, b }, δ, q0, { q0, q3 }).

| State | a | b |
| --- | --- | --- |
| →*q0 | q1 | q0 |
| q1 | q2 | dead |
| q2 | q3 | dead |
| *q3 | dead | q0 |

| Input | State sequence | Result |
| --- | --- | --- |
| aaa | q0, q1, q2, q3 | Accepted |
| baaab | q0, q0, q1, q2, q3, q0 | Accepted |
| aaabaaa | q0, q1, q2, q3, q0, q1, q2, q3 | Accepted |
| aa | q0, q1, q2 | Rejected |
| aaaa | q0, q1, q2, q3, dead | Rejected |
| aba | q0, q1, dead | Rejected |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the strings in which every block of a's has length three.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

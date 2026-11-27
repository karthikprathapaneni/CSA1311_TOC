# Experiment 05: DFA for an even number of a's

Aim: To design a DFA using the simulator that accepts the strings over {a, b} with an even number of a's.

Design: two states are enough. q0 means "an even number of a's so far" and is both the start state and the accepting state (zero a's is even). q1 means "an odd number of a's so far". Each a toggles between q0 and q1, and b leaves the state unchanged.

M = ({ q0, q1 }, { a, b }, δ, q0, { q0 }).

| State | a | b |
| --- | --- | --- |
| →*q0 | q1 | q0 |
| q1 | q0 | q1 |

Procedure: open the DFA simulator, create states q0 and q1, mark q0 as the initial and final state, add the transitions in the table, and run the test strings below.

| Input | State sequence | Result |
| --- | --- | --- |
| abab | q0, q1, q1, q0, q0 | Accepted (2 a's) |
| aab | q0, q1, q0, q0 | Accepted (2 a's) |
| ab | q0, q1, q1 | Rejected (1 a) |
| bbb | q0, q0, q0, q0 | Accepted (0 a's) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the strings with an even number of a's.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

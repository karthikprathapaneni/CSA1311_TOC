# Experiment 12: DFA that accepts the strings a, ac and bac

Aim: To design a DFA using the simulator that accepts exactly the input strings a, ac and bac over the alphabet { a, b, c }.

Design: the language is finite, so the DFA is a short chain of states, one for each prefix of the accepted strings. q1 (after a) is accepting. The strings ac and bac end in the same way, so they share one accepting state q2 with no outgoing moves. Every move that is not listed leads to a dead (trap) state, which can be left out of the simulator drawing.

M = ({ q0, q1, q2, q3, q4 }, { a, b, c }, δ, q0, { q1, q2 }) with q3 meaning "read b" and q4 meaning "read ba".

| State | a | b | c |
| --- | --- | --- | --- |
| →q0 | q1 | q3 | dead |
| *q1 | dead | dead | q2 |
| *q2 | dead | dead | dead |
| q3 | q4 | dead | dead |
| q4 | dead | dead | q2 |

| Input | State sequence | Result |
| --- | --- | --- |
| a | q0, q1 | Accepted |
| ac | q0, q1, q2 | Accepted |
| bac | q0, q3, q4, q2 | Accepted |
| ba | q0, q3, q4 | Rejected (q4 is not final) |
| aca | q0, q1, q2, dead | Rejected |
| b | q0, q3 | Rejected |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The DFA accepts exactly the three strings a, ac and bac.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

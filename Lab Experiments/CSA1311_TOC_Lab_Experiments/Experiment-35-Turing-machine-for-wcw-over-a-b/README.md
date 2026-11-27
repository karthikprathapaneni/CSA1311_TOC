# Experiment 35: Turing machine for wcw over { a, b }

Aim: To design a Turing machine using the simulator that accepts the strings wcw, where w is any string over { a, b }.

Design: the machine takes the first symbol of the left w, changes it to X, and remembers it (q1 for a, q2 for b). It runs right past c, skips the X's already used in the right part, and checks that the first unmarked symbol is the same, changing it to X. It then returns to the left (q5, q6) and repeats. When the left part has no symbols left (q0 reads c), q7 checks that only X's remain on the right of c. Any mismatch leaves the machine with no move. Since w may be empty, the string c is accepted.

M = ({ q0, …, q8 }, { a, b, c }, { a, b, c, X, B }, δ, q0, B, { q8 }).

| State | X | a | b | c | B |
| --- | --- | --- | --- | --- | --- |
| →q0 | – | (q1, X, R) | (q2, X, R) | (q7, c, R) | – |
| q1 | – | (q1, a, R) | (q1, b, R) | (q3, c, R) | – |
| q2 | – | (q2, a, R) | (q2, b, R) | (q4, c, R) | – |
| q3 | (q3, X, R) | (q5, X, L) | – | – | – |
| q4 | (q4, X, R) | – | (q5, X, L) | – | – |
| q5 | (q5, X, L) | – | – | (q6, c, L) | – |
| q6 | (q0, X, R) | (q6, a, L) | (q6, b, L) | – | – |
| q7 | (q7, X, R) | – | – | – | (q8, B, R) |
| *q8 | – | – | – | – | – |

Trace of abcab:

q0abcab ⊢ Xq1bcab ⊢ Xbq1cab ⊢ Xbcq3ab ⊢ Xbq5cXb ⊢ Xq6bcXb ⊢ q6XbcXb
        ⊢ Xq0bcXb ⊢ XXq2cXb ⊢ XXcq4Xb ⊢ XXcXq4b ⊢ XXcq5XX ⊢ XXq5cXX
        ⊢ Xq6XcXX ⊢ XXq0cXX ⊢ XXcq7XX ⊢ XXcXq7X ⊢ XXcXXq7B ⊢ XXcXXBq8B

For abcba the trace is q0abcba ⊢ Xq1bcba ⊢ Xbq1cba ⊢ Xbcq3ba, and q3 has no move on b, so abcba is rejected.

| Input | Result |
| --- | --- |
| abcab, aacaa, c | Accepted |
| abcba | Rejected (the right w differs from the left w) |
| abca | Rejected (the right w is shorter) |
| ab, cc | Rejected (the string must contain exactly one c) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the strings wcw over { a, b }.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

# Experiment 31: Turing machine for ww over { a, b }

Aim: To design a Turing machine using the simulator that accepts the strings ww, where w is any string over { a, b }.

Design: the machine works in two passes. Pass 1 (q0 to q3) finds the middle: it marks the leftmost unmarked symbol as P (for a) or Q (for b), and the rightmost unmarked symbol as U (for a) or V (for b). If the marks do not meet exactly, the length is odd and the string is rejected. Pass 2 (q4 to q7) compares the two halves in order: it takes the leftmost P or Q, changes it to X, and checks that the leftmost unmarked U or V is the same letter, changing it to Y. When no P or Q is left (q5 reads Y), the halves are equal, and the machine accepts. The empty string is ww with w = ε and is accepted.

M = ({ q0, …, q8 }, { a, b }, { a, b, P, Q, U, V, X, Y, B }, δ, q0, B, { q8 }).

| State | P | Q | U | V | X | Y | a | b | B |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| →q0 | – | – | (q4, U, L) | (q4, V, L) | – | – | (q1, P, R) | (q1, Q, R) | (q8, B, R) |
| q1 | – | – | (q2, U, L) | (q2, V, L) | – | – | (q1, a, R) | (q1, b, R) | (q2, B, L) |
| q2 | – | – | – | – | – | – | (q3, U, L) | (q3, V, L) | – |
| q3 | (q0, P, R) | (q0, Q, R) | – | – | – | – | (q3, a, L) | (q3, b, L) | – |
| q4 | (q4, P, L) | (q4, Q, L) | – | – | (q4, X, L) | (q4, Y, L) | – | – | (q5, B, R) |
| q5 | (q6, X, R) | (q7, X, R) | – | – | (q5, X, R) | (q8, Y, R) | – | – | – |
| q6 | (q6, P, R) | (q6, Q, R) | (q4, Y, L) | – | – | (q6, Y, R) | – | – | – |
| q7 | (q7, P, R) | (q7, Q, R) | – | (q4, Y, L) | – | (q7, Y, R) | – | – | – |
| *q8 | – | – | – | – | – | – | – | – | – |

In pass 2, q6 carries an a and q7 carries a b to the right half.

Trace of abab:

q0abab ⊢ Pq1bab ⊢ Pbq1ab ⊢ Pbaq1b ⊢ Pbabq1B ⊢ Pbaq2b ⊢ Pbq3aV ⊢ Pq3baV
       ⊢ q3PbaV ⊢ Pq0baV ⊢ PQq1aV ⊢ PQaq1V ⊢ PQq2aV ⊢ Pq3QUV ⊢ PQq0UV
       ⊢ Pq4QUV ⊢ q4PQUV ⊢ q4BPQUV ⊢ q5PQUV ⊢ Xq6QUV ⊢ XQq6UV ⊢ Xq4QYV
       ⊢ q4XQYV ⊢ q4BXQYV ⊢ q5XQYV ⊢ Xq5QYV ⊢ XXq7YV ⊢ XXYq7V ⊢ XXq4YY
       ⊢ Xq4XYY ⊢ q4XXYY ⊢ q4BXXYY ⊢ q5XXYY ⊢ Xq5XYY ⊢ XXq5YY ⊢ XXYq8Y

The machine reaches q8, so abab = (ab)(ab) is accepted.

| Input | Result |
| --- | --- |
| abab, aa, aabaab, ε | Accepted |
| aba | Rejected (odd length) |
| abba, abaa | Rejected (the two halves differ) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the strings of the form ww over { a, b }.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

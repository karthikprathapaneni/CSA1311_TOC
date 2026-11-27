# Experiment 34: Turing machine for even-length palindromes over { a, b }

Aim: To design a Turing machine using the simulator that accepts the palindromes of even length over { a, b }.

Design: the machine is the one of Experiment 30 with the two accepting conditions swapped. It erases the first symbol, runs to the right end and erases the last symbol only if it is the same, then returns to the left end. If a symbol is left alone in the middle (q1 or q4 reads B), the length is odd and there is no move, so the string is rejected. If every symbol has been erased in pairs (q0 reads B), the string is accepted. The empty string is accepted.

M = ({ q0, q1, q2, q3, q4, q5, q6, q7, q8 }, { a, b }, { a, b, B }, δ, q0, B, { q8 }).

| State | a | b | B |
| --- | --- | --- | --- |
| →q0 | (q1, B, R) | (q4, B, R) | (q8, B, R) |
| q1 | (q2, a, R) | (q2, b, R) | – |
| q2 | (q2, a, R) | (q2, b, R) | (q3, B, L) |
| q3 | (q7, B, L) | – | – |
| q4 | (q5, a, R) | (q5, b, R) | – |
| q5 | (q5, a, R) | (q5, b, R) | (q6, B, L) |
| q6 | – | (q7, B, L) | – |
| q7 | (q7, a, L) | (q7, b, L) | (q0, B, R) |
| *q8 | – | – | – |

Trace of abba:

q0abba ⊢ q1bba ⊢ bq2ba ⊢ bbq2a ⊢ bbaq2B ⊢ bbq3a ⊢ bq7b ⊢ q7bb
       ⊢ q7Bbb ⊢ q0bb ⊢ q4b ⊢ bq5B ⊢ q6b ⊢ q7B ⊢ q0B ⊢ q8B

| Input | Result |
| --- | --- |
| abba, aa, aabbaa, ε | Accepted |
| aba, a | Rejected (odd length) |
| ab, abaa | Rejected (not a palindrome) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the palindromes of even length over { a, b }.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

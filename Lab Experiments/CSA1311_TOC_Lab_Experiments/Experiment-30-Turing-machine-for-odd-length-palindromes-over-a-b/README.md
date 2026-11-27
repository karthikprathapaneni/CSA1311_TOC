# Experiment 30: Turing machine for odd-length palindromes over { a, b }

Aim: To design a Turing machine using the simulator that accepts the palindromes of odd length over { a, b }.

Design: in each round the machine erases the first symbol (q0), remembers whether it was a (q1, q2, q3) or b (q4, q5, q6), runs to the right end, and erases the last symbol only if it is the same. Then q7 returns to the left end for the next round. When the first symbol has been erased and the next cell is blank (q1 or q4 reads B), exactly one symbol was left in the middle, so the length is odd and the string is accepted. If the rounds finish with nothing in the middle (q0 reads B), the length is even and the string is rejected.

M = ({ q0, q1, q2, q3, q4, q5, q6, q7, q8 }, { a, b }, { a, b, B }, δ, q0, B, { q8 }).

| State | a | b | B |
| --- | --- | --- | --- |
| →q0 | (q1, B, R) | (q4, B, R) | – |
| q1 | (q2, a, R) | (q2, b, R) | (q8, B, R) |
| q2 | (q2, a, R) | (q2, b, R) | (q3, B, L) |
| q3 | (q7, B, L) | – | – |
| q4 | (q5, a, R) | (q5, b, R) | (q8, B, R) |
| q5 | (q5, a, R) | (q5, b, R) | (q6, B, L) |
| q6 | – | (q7, B, L) | – |
| q7 | (q7, a, L) | (q7, b, L) | (q0, B, R) |
| *q8 | – | – | – |

Trace of aba:

q0aba ⊢ q1ba ⊢ bq2a ⊢ baq2B ⊢ bq3a ⊢ q7b ⊢ q7Bb ⊢ q0b ⊢ q4B ⊢ q8B

After the outer a's are erased the middle b is left, q4 finds the blank next to it, and the machine accepts.

| Input | Result |
| --- | --- |
| a, aba, abbba, babab | Accepted |
| aa, abba | Rejected (even length) |
| ab, abb | Rejected (not a palindrome) |
| ε | Rejected (length 0 is even) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the palindromes of odd length over { a, b }.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

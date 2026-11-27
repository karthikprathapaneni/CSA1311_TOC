# Experiment 38: Turing machine for all palindromes over { a, b }

Aim: To design a Turing machine using the simulator that accepts all palindromes, of odd and even length, over { a, b }.

Design: the machine joins Experiments 30 and 34. It erases the first symbol, then the matching last symbol, and repeats. A palindrome ends in one of two ways: nothing is left (q0 reads B, even length) or one symbol is left in the middle (q1 or q4 reads B, odd length). Both lead to the final state q8. The empty string is accepted.

M = ({ q0, q1, q2, q3, q4, q5, q6, q7, q8 }, { a, b }, { a, b, B }, δ, q0, B, { q8 }).

| State | a | b | B |
| --- | --- | --- | --- |
| →q0 | (q1, B, R) | (q4, B, R) | (q8, B, R) |
| q1 | (q2, a, R) | (q2, b, R) | (q8, B, R) |
| q2 | (q2, a, R) | (q2, b, R) | (q3, B, L) |
| q3 | (q7, B, L) | – | – |
| q4 | (q5, a, R) | (q5, b, R) | (q8, B, R) |
| q5 | (q5, a, R) | (q5, b, R) | (q6, B, L) |
| q6 | – | (q7, B, L) | – |
| q7 | (q7, a, L) | (q7, b, L) | (q0, B, R) |
| *q8 | – | – | – |

Trace of abbba:

q0abbba ⊢ q1bbba ⊢ bq2bba ⊢ bbq2ba ⊢ bbbq2a ⊢ bbbaq2B ⊢ bbbq3a ⊢ bbq7b
        ⊢ bq7bb ⊢ q7bbb ⊢ q7Bbbb ⊢ q0bbb ⊢ q4bb ⊢ bq5b ⊢ bbq5B ⊢ bq6b
        ⊢ q7b ⊢ q7Bb ⊢ q0b ⊢ q4B ⊢ q8B

For ab the trace is q0ab ⊢ q1b ⊢ bq2B ⊢ q3b, and q3 has no move on b, so ab is rejected.

| Input | Result |
| --- | --- |
| abbba, abba, a, ε | Accepted |
| ab, abb, aab | Rejected (not a palindrome) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the palindromes over { a, b }.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

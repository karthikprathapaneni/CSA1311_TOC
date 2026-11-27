# Experiment 37: Turing machine for string comparison (w#w)

Aim: To design a Turing machine using the simulator that compares two strings over { a, b } written either side of a # separator, and accepts when they are equal, for example aba#aba.

Design: the machine takes the leftmost unmarked symbol of the first string, changes it to X and remembers it (q1 for a, q2 for b). It crosses #, skips the X's already used in the second string, and checks that the first unmarked symbol is the same, changing it to X. It then returns to the left (q5, q6) and repeats. When the first string has no symbols left (q0 reads #), q7 checks that only X's remain in the second string. If the strings differ in a symbol or in length, no move exists and the machine rejects.

M = ({ q0, …, q8 }, { a, b, # }, { a, b, #, X, B }, δ, q0, B, { q8 }).

| State | # | X | a | b | B |
| --- | --- | --- | --- | --- | --- |
| →q0 | (q7, #, R) | – | (q1, X, R) | (q2, X, R) | – |
| q1 | (q3, #, R) | – | (q1, a, R) | (q1, b, R) | – |
| q2 | (q4, #, R) | – | (q2, a, R) | (q2, b, R) | – |
| q3 | – | (q3, X, R) | (q5, X, L) | – | – |
| q4 | – | (q4, X, R) | – | (q5, X, L) | – |
| q5 | (q6, #, L) | (q5, X, L) | – | – | – |
| q6 | – | (q0, X, R) | (q6, a, L) | (q6, b, L) | – |
| q7 | – | (q7, X, R) | – | – | (q8, B, R) |
| *q8 | – | – | – | – | – |

Trace of aba#aba:

q0aba#aba ⊢ Xq1ba#aba ⊢ Xbq1a#aba ⊢ Xbaq1#aba ⊢ Xba#q3aba ⊢ Xbaq5#Xba
          ⊢ Xbq6a#Xba ⊢ Xq6ba#Xba ⊢ q6Xba#Xba ⊢ Xq0ba#Xba ⊢ XXq2a#Xba
          ⊢ XXaq2#Xba ⊢ XXa#q4Xba ⊢ XXa#Xq4ba ⊢ XXa#q5XXa ⊢ XXaq5#XXa
          ⊢ XXq6a#XXa ⊢ Xq6Xa#XXa ⊢ XXq0a#XXa ⊢ XXXq1#XXa ⊢ XXX#q3XXa
          ⊢ XXX#Xq3Xa ⊢ XXX#XXq3a ⊢ XXX#Xq5XX ⊢ XXX#q5XXX ⊢ XXXq5#XXX
          ⊢ XXq6X#XXX ⊢ XXXq0#XXX ⊢ XXX#q7XXX ⊢ XXX#Xq7XX ⊢ XXX#XXq7X
          ⊢ XXX#XXXq7B ⊢ XXX#XXXBq8B

The machine reaches q8, so the two strings are equal and aba#aba is accepted.

| Input | Result |
| --- | --- |
| aba#aba, ab#ab, # | Accepted (the strings are equal) |
| aba#abb | Rejected (the third symbols differ) |
| ab#aba | Rejected (the second string is longer) |
| aba | Rejected (there is no # separator) |

> Screenshot reminder: the original laboratory record asks for a simulator screenshot here. Add your own screenshot after running the design.

## Result

Result: The Turing machine accepts exactly the inputs u#v in which u and v are the same string.

## Implementation note

This is a simulator/drawing-based experiment in the supplied record. Use the state/transition or move table above to build it in the required automata simulator, then add a screenshot of the completed design and test run.

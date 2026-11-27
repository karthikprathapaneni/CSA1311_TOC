# Experiment 04: NFA for strings that start with 0 and end with 1

Aim: To write a C program that simulates an NFA accepting the strings over {0, 1} that start with 0 and end with 1.

## Algorithm

Define the NFA N = ({ q0, q1, q2 }, { 0, 1 }, δ, q0, { q2 }) with q0 –0→ q1, q1 looping on 0 and 1, and q1 –1→ q2.

Keep the active states as a bit mask, starting with { q0 }.

For each symbol, the new set is the union of δ(q, symbol) over the active states.

Accept if the set contains q2 when the string ends.

## Transition table

| State | 0 | 1 |
| --- | --- | --- |
| →q0 | { q1 } | ∅ |
| q1 | { q1 } | { q1, q2 } |
| *q2 | ∅ | ∅ |

## Program

## Output

Enter a string over {0,1}: 0011
  start: {q0}
  after 0: {q1}
  after 0: {q1}
  after 1: {q1,q2}
  after 1: {q1,q2}
The string 0011 is ACCEPTED

Enter a string over {0,1}: 0110
  start: {q0}
  after 0: {q1}
  after 1: {q1,q2}
  after 1: {q1,q2}
  after 0: {q1}
The string 0110 is REJECTED

## Result

Result: The NFA was simulated in C. 0011 is accepted (it ends in a set containing q2), and 0110 is rejected because it ends with 0.

## Source file

Compile and run `program.c` using a C compiler.

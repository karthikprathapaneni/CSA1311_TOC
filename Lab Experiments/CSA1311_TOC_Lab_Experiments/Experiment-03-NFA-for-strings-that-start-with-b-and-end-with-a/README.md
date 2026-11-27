# Experiment 03: NFA for strings that start with b and end with a

Aim: To write a C program that simulates an NFA accepting the strings over {a, b} that start with b and end with a.

## Algorithm

Define the NFA N = ({ q0, q1, q2 }, { a, b }, δ, q0, { q2 }) with q0 –b→ q1, q1 looping on a and b, and q1 –a→ q2.

Keep the set of currently active states as a bit mask (bit i is 1 when qi is active). Start with { q0 }.

For each input symbol, the new set is the union of δ(q, symbol) over every active state q.

At the end of the string, accept if the set contains the final state q2.

## Transition table

| State | a | b |
| --- | --- | --- |
| →q0 | ∅ | { q1 } |
| q1 | { q1, q2 } | { q1 } |
| *q2 | ∅ | ∅ |

## Program

## Output

Enter a string over {a,b}: baba
  start: {q0}
  after b: {q1}
  after a: {q1,q2}
  after b: {q1}
  after a: {q1,q2}
The string baba is ACCEPTED

Enter a string over {a,b}: bab
  start: {q0}
  after b: {q1}
  after a: {q1,q2}
  after b: {q1}
The string bab is REJECTED

## Result

Result: The NFA was simulated in C by tracking the set of active states. baba is accepted because q2 is in the final set, and bab is rejected because the last symbol takes the machine back to { q1 }.

## Source file

Compile and run `program.c` using a C compiler.

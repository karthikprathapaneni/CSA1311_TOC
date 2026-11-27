# Experiment 02: DFA for strings that start with 0 and end with 1

Aim: To write a C program that simulates a DFA accepting the strings over {0, 1} that start with 0 and end with 1.

## Algorithm

Define the DFA M = ({ q0, q1, q2, q3 }, { 0, 1 }, δ, q0, { q2 }).

Read the input string and start in q0.

For each symbol, move to the state given by δ.

Accept if the final state reached is q2, otherwise reject.

State meanings: q1 means the string started with 0 and the last symbol is 0; q2 means it started with 0 and the last symbol is 1 (final); q3 is a dead state (the string started with 1).

## Transition table

| State | 0 | 1 |
| --- | --- | --- |
| →q0 | q1 | q3 |
| q1 | q1 | q2 |
| *q2 | q1 | q2 |
| q3 | q3 | q3 |

## Program

## Output

Enter a string over {0,1}: 0101
  delta(q0, 0) = q1
  delta(q1, 1) = q2
  delta(q2, 0) = q1
  delta(q1, 1) = q2
The string 0101 is ACCEPTED

Enter a string over {0,1}: 1001
  delta(q0, 1) = q3
  delta(q3, 0) = q3
  delta(q3, 0) = q3
  delta(q3, 1) = q3
The string 1001 is REJECTED

## Result

Result: The DFA was simulated in C. 0101 is accepted, and 1001 is rejected because it starts with 1 and falls into the dead state.

## Source file

Compile and run `program.c` using a C compiler.

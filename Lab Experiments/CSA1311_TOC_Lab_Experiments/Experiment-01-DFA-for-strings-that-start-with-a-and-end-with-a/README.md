# Experiment 01: DFA for strings that start with a and end with a

Aim: To write a C program that simulates a DFA accepting the strings over {a, b} that start with a and end with a.

## Algorithm

Define the DFA M = ({ q0, q1, q2, q3 }, { a, b }, δ, q0, { q1 }).

Read the input string.

Start in q0. For each symbol, move to the state given by δ.

When the string ends, accept if the current state is q1, otherwise reject.

State meanings: q0 is the start state; q1 means the string started with a and the last symbol is a (final); q2 means it started with a and the last symbol is b; q3 is a dead state (the string started with b).

## Transition table

| State | a | b |
| --- | --- | --- |
| →q0 | q1 | q3 |
| *q1 | q1 | q2 |
| q2 | q1 | q2 |
| q3 | q3 | q3 |

## Program

## Output

Enter a string over {a,b}: abba
  delta(q0, a) = q1
  delta(q1, b) = q2
  delta(q2, b) = q2
  delta(q2, a) = q1
The string abba is ACCEPTED

Enter a string over {a,b}: abab
  delta(q0, a) = q1
  delta(q1, b) = q2
  delta(q2, a) = q1
  delta(q1, b) = q2
The string abab is REJECTED

## Result

Result: The DFA was simulated in C. abba (starts and ends with a) is accepted, and abab (ends with b) is rejected.

## Source file

Compile and run `program.c` using a C compiler.

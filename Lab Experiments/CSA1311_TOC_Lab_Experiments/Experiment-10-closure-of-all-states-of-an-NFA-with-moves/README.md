# Experiment 10: ε-closure of all states of an NFA with ε-moves

Aim: To write a C program that finds the ε-closure of every state of an NFA with ε-moves.

## Algorithm

Read the number of states n and the number of ε-transitions m.

Read the m ε-transitions as pairs (from, to) and store them in an n × n matrix eps.

For each state i, clear the visited array and run a depth-first search from i that follows only ε-moves, marking every state reached.

The ε-closure of i is the set of marked states (it always contains i itself). Print it.

The visited array stops the search from looping forever when the ε-moves contain a cycle.

## Program

Output (NFA with ε-moves q0 → q1 and q1 → q2)

Enter the number of states: 3
Enter the number of epsilon-transitions: 2
Enter each epsilon-transition as: from to
0 1
1 2

Epsilon-closures:
e-closure(q0) = {q0, q1, q2}
e-closure(q1) = {q1, q2}
e-closure(q2) = {q2}

## Result

Result: The program finds the ε-closure of every state of the NFA. For this NFA the closures are { q0, q1, q2 }, { q1, q2 } and { q2 }.

## Source file

Compile and run `program.c` using a C compiler.

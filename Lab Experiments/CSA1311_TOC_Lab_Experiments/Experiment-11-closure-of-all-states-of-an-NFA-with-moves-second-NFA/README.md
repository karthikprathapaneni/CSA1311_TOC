# Experiment 11: ε-closure of all states of an NFA with ε-moves (second NFA)

Aim: To find the ε-closure of every state of an NFA with ε-moves using a C program.

The list repeats Experiment 10 here, so the same program is run on a different NFA with five states and an ε-cycle between q1 and q2, to show that the visited array handles cycles.

Algorithm and program: as in Experiment 10.

Output (ε-moves q0 → q1, q0 → q3, q1 → q2, q2 → q1, q3 → q4)

Enter the number of states: 5
Enter the number of epsilon-transitions: 5
Enter each epsilon-transition as: from to
0 1
0 3
1 2
2 1
3 4

Epsilon-closures:
e-closure(q0) = {q0, q1, q2, q3, q4}
e-closure(q1) = {q1, q2}
e-closure(q2) = {q1, q2}
e-closure(q3) = {q3, q4}
e-closure(q4) = {q4}

## Result

Result: The program finds all ε-closures correctly, including for states q1 and q2 that form an ε-cycle.

## Source file

Compile and run `program.c` using a C compiler.

The same program is run with the second NFA input shown in this experiment.

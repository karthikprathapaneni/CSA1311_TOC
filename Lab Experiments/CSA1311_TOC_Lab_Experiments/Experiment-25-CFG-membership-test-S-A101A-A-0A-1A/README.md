# Experiment 25: CFG membership test: S → A101A, A → 0A | 1A | ε

Aim: To write a C program that checks whether a given string belongs to the language defined by the context-free grammar G: S → A101A, A → 0A | 1A | ε.

Language: A derives every string over {0, 1}, so S derives x101y for any x, y ∈ {0, 1}*. L(G) is the set of strings over {0, 1} that contain 101 as a substring.

## Algorithm

Read the input string (an empty line stands for ε).

derive_A(s, from, to) applies A → 0A | 1A | ε: the part between from and to must contain only 0's and 1's.

derive_S(s) applies S → A101A. For every position k, check whether s[k..k+2] is 101, whether the part before it can be derived by the first A, and whether the part after it can be derived by the second A.

Accept if some position k works, otherwise reject.

## Program

## Output

Enter a string over {0,1} (empty line for epsilon): 1101011
The string "1101011" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0010100
The string "0010100" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0100
The string "0100" does not belong to the language of the CFG: REJECTED

Enter a string over {0,1} (empty line for epsilon): 1100
The string "1100" does not belong to the language of the CFG: REJECTED

## Result

Result: The program accepts exactly the strings over {0, 1} that contain 101. 1101011 = 1 · 101 · 011 and 0010100 = 0 · 101 · 00 are accepted; 0100 and 1100 do not contain 101 and are rejected.

Testing of Experiments 21–25: each program was compared with an independent check of its language on all 511 strings over {0, 1} of length 0 to 8, with no mismatches.

## Source file

Compile and run `program.c` using a C compiler.

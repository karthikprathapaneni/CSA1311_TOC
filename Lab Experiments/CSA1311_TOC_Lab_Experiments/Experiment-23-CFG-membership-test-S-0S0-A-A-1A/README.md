# Experiment 23: CFG membership test: S → 0S0 | A, A → 1A | ε

Aim: To write a C program that checks whether a given string belongs to the language defined by the context-free grammar G: S → 0S0 | A, A → 1A | ε.

Language: A derives 1^m (any number of 1's, possibly none). Each use of S → 0S0 adds one 0 on each side, so S derives 0^n 1^m 0^n. L(G) = { 0^n 1^m 0^n : n, m ≥ 0 }. For example 00, 0110, 001100 and 111 are in L(G), but 000 and 0100 are not.

## Algorithm

Read the input string (an empty line stands for ε).

derive_A(s, i, j) applies A → 1A | ε: the part s[i..j] must contain only 1's (an empty part is allowed).

derive_S(s, i, j) applies S → 0S0 while the part has at least two symbols and both ends are 0, and calls itself on the inside.

When S → 0S0 no longer applies, the remaining part must be derived by S → A. Accept if it is all 1's, otherwise reject.

## Program

## Output

Enter a string over {0,1} (empty line for epsilon): 001100
The string "001100" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0110
The string "0110" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0100
The string "0100" does not belong to the language of the CFG: REJECTED

Enter a string over {0,1} (empty line for epsilon): 000
The string "000" does not belong to the language of the CFG: REJECTED

## Result

Result: The program accepts exactly the strings of the form 0^n 1^m 0^n. 001100 (n = 2, m = 2) and 0110 (n = 1, m = 2) are accepted; 0100 and 000 are rejected because the number of 0's on the two sides cannot be matched with only 1's in the middle.

## Source file

Compile and run `program.c` using a C compiler.

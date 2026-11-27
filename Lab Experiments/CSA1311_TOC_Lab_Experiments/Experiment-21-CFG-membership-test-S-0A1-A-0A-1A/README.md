# Experiment 21: CFG membership test: S → 0A1, A → 0A | 1A | ε

Aim: To write a C program that checks whether a given string belongs to the language defined by the context-free grammar G: S → 0A1, A → 0A | 1A | ε.

Language: A derives every string over {0, 1}, so S derives a string that starts with 0, ends with 1, and has any string over {0, 1} in between. L(G) = { 0w1 : w ∈ {0, 1}* }, and the shortest string in L(G) is 01.

## Algorithm

Read the input string (an empty line stands for ε).

Write one function for each non-terminal. derive_A(s, from, to) applies A → 0A | 1A | ε: it accepts the part of the string between from and to if every symbol is 0 or 1.

derive_S(s) applies S → 0A1: the string must have at least 2 symbols, start with 0 and end with 1, and the part in between must be derived by A.

Print ACCEPTED if derive_S returns 1, otherwise print REJECTED.

## Program

## Output

Enter a string over {0,1} (empty line for epsilon): 0111
The string "0111" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0110
The string "0110" does not belong to the language of the CFG: REJECTED

Enter a string over {0,1} (empty line for epsilon): 1001
The string "1001" does not belong to the language of the CFG: REJECTED

## Result

Result: The program checks membership in L(G). 0111 = 0 · 11 · 1 is accepted. 0110 is rejected because it ends with 0, and 1001 is rejected because it starts with 1.

## Source file

Compile and run `program.c` using a C compiler.

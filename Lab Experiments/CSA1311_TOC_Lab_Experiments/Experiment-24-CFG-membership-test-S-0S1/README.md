# Experiment 24: CFG membership test: S → 0S1 | ε

Aim: To write a C program that checks whether a given string belongs to the language defined by the context-free grammar G: S → 0S1 | ε.

Language: each use of S → 0S1 adds one 0 on the left and one 1 on the right, and S → ε stops the derivation. So L(G) = { 0^n 1^n : n ≥ 0 }. This language is context-free but not regular, because matching the counts needs unbounded memory.

## Algorithm

Read the input string (an empty line stands for ε).

derive_S(s, i, j) tries to derive the part s[i..j] from S.

If the part is empty (i > j), use S → ε and accept.

Otherwise the part must have at least two symbols, start with 0 and end with 1; use S → 0S1 and call derive_S on s[i+1..j-1]. If this fails, reject.

## Program

## Output

Enter a string over {0,1} (empty line for epsilon): 000111
The string "000111" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0011
The string "0011" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0101
The string "0101" does not belong to the language of the CFG: REJECTED

Enter a string over {0,1} (empty line for epsilon): 001
The string "001" does not belong to the language of the CFG: REJECTED

Enter a string over {0,1} (empty line for epsilon): 
The string "" belongs to the language of the CFG: ACCEPTED

## Result

Result: The program accepts exactly the strings 0^n 1^n. 000111 and 0011 are accepted, ε is accepted (n = 0), 0101 is rejected because the 0's and 1's are not in two blocks, and 001 is rejected because the counts differ.

## Source file

Compile and run `program.c` using a C compiler.

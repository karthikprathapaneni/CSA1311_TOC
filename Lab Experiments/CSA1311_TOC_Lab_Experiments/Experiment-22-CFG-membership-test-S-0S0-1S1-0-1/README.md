# Experiment 22: CFG membership test: S → 0S0 | 1S1 | 0 | 1 | ε

Aim: To write a C program that checks whether a given string belongs to the language defined by the context-free grammar G: S → 0S0 | 1S1 | 0 | 1 | ε.

Language: the rules S → 0S0 and S → 1S1 put the same symbol at both ends, and S → 0, S → 1 and S → ε end the derivation with an odd or an even centre. So L(G) is the set of all palindromes over {0, 1}, including ε.

## Algorithm

Read the input string (an empty line stands for ε).

derive_S(s, i, j) tries to derive the part s[i..j] from S.

If the part is empty (i > j), use S → ε. If it has one symbol (i = j), use S → 0 or S → 1.

Otherwise the two end symbols must be equal; use S → 0S0 or S → 1S1 and call derive_S on s[i+1..j-1]. If the end symbols differ, no rule applies and the string is rejected.

## Program

## Output

Enter a string over {0,1} (empty line for epsilon): 10101
The string "10101" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 0110
The string "0110" belongs to the language of the CFG: ACCEPTED

Enter a string over {0,1} (empty line for epsilon): 011
The string "011" does not belong to the language of the CFG: REJECTED

Enter a string over {0,1} (empty line for epsilon): 
The string "" belongs to the language of the CFG: ACCEPTED

## Result

Result: The program accepts exactly the palindromes over {0, 1}. 10101 (odd length) and 0110 (even length) are accepted, the empty string is accepted through S → ε, and 011 is rejected because it is not a palindrome.

## Source file

Compile and run `program.c` using a C compiler.

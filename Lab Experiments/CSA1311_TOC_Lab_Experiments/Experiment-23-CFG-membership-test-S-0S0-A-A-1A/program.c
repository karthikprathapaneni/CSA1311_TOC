/* Experiment 23: membership test for the CFG   S -> 0S0 | A,  A -> 1A | epsilon
   L = { 0^n 1^m 0^n : n, m >= 0 }.                                              */
#include <stdio.h>
#include <string.h>

/* A -> 1A | epsilon : s[i..j] (inclusive) must consist of 1's only */
static int derive_A(const char *s, int i, int j)
{
    for (; i <= j; i++)
        if (s[i] != '1') return 0;
    return 1;
}

/* S -> 0S0 | A : strip a matching pair of 0's while possible, then use S -> A */
static int derive_S(const char *s, int i, int j)
{
    if (i < j && s[i] == '0' && s[j] == '0')
        return derive_S(s, i + 1, j - 1);      /* S -> 0S0 */
    return derive_A(s, i, j);                  /* S -> A   */
}

int main(void)
{
    char s[100];
    printf("Enter a string over {0,1} (empty line for epsilon): ");
    if (fgets(s, sizeof s, stdin) == NULL) s[0] = '\0';
    s[strcspn(s, "\r\n")] = '\0';

    if (derive_S(s, 0, (int)strlen(s) - 1))
        printf("The string \"%s\" belongs to the language of the CFG: ACCEPTED\n", s);
    else
        printf("The string \"%s\" does not belong to the language of the CFG: REJECTED\n", s);
    return 0;
}

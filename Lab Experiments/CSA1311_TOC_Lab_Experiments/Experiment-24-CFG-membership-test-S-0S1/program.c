/* Experiment 24: membership test for the CFG   S -> 0S1 | epsilon
   L = { 0^n 1^n : n >= 0 }.                                                     */
#include <stdio.h>
#include <string.h>

/* derive s[i..j] (inclusive) from S */
static int derive_S(const char *s, int i, int j)
{
    if (i > j) return 1;                                   /* S -> epsilon */
    if (s[i] == '0' && s[j] == '1' && i < j)
        return derive_S(s, i + 1, j - 1);                  /* S -> 0S1     */
    return 0;
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

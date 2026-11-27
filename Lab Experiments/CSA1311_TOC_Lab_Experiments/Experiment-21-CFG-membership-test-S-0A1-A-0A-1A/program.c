/* Experiment 21: membership test for the CFG   S -> 0A1,  A -> 0A | 1A | epsilon
   A derives every string over {0,1}, so L = { 0 w 1 : w in {0,1}* }.            */
#include <stdio.h>
#include <string.h>

/* A -> 0A | 1A | epsilon : accept if every symbol of s[from..to-1] is 0 or 1 */
static int derive_A(const char *s, int from, int to)
{
    int i;
    for (i = from; i < to; i++)
        if (s[i] != '0' && s[i] != '1')
            return 0;
    return 1;
}

/* S -> 0A1 : first symbol 0, last symbol 1, and the middle must be derived by A */
static int derive_S(const char *s)
{
    int n = (int)strlen(s);
    if (n < 2) return 0;
    if (s[0] != '0' || s[n - 1] != '1') return 0;
    return derive_A(s, 1, n - 1);
}

int main(void)
{
    char s[100];
    printf("Enter a string over {0,1} (empty line for epsilon): ");
    if (fgets(s, sizeof s, stdin) == NULL) s[0] = '\0';
    s[strcspn(s, "\r\n")] = '\0';

    if (derive_S(s))
        printf("The string \"%s\" belongs to the language of the CFG: ACCEPTED\n", s);
    else
        printf("The string \"%s\" does not belong to the language of the CFG: REJECTED\n", s);
    return 0;
}

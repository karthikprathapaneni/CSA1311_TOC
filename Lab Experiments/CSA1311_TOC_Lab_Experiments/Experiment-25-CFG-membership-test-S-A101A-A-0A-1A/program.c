/* Experiment 25: membership test for the CFG   S -> A101A,  A -> 0A | 1A | epsilon
   A derives every string over {0,1}, so L = strings over {0,1} that contain 101. */
#include <stdio.h>
#include <string.h>

/* A -> 0A | 1A | epsilon : s[from..to-1] must contain only 0's and 1's */
static int derive_A(const char *s, int from, int to)
{
    int i;
    for (i = from; i < to; i++)
        if (s[i] != '0' && s[i] != '1') return 0;
    return 1;
}

/* S -> A101A : try every position k where the middle part 101 can sit */
static int derive_S(const char *s)
{
    int n = (int)strlen(s), k;
    for (k = 0; k + 3 <= n; k++)
        if (s[k] == '1' && s[k + 1] == '0' && s[k + 2] == '1' &&
            derive_A(s, 0, k) && derive_A(s, k + 3, n))
            return 1;
    return 0;
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

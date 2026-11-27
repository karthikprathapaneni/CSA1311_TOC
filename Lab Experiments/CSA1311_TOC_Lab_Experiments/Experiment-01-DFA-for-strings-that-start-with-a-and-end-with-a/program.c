/* Experiment 1: DFA simulation - strings over {a,b} that start with a and end with a */
#include <stdio.h>

int main(void)
{
    /* States: 0 = start, 1 = started with a and last symbol is a (final),
       2 = started with a and last symbol is b, 3 = dead (started with b)  */
    int delta[4][2] = {
        /*        a  b */
        /* q0 */ {1, 3},
        /* q1 */ {1, 2},
        /* q2 */ {1, 2},
        /* q3 */ {3, 3}
    };
    int final_state = 1;
    char s[100];
    int state = 0, i;

    printf("Enter a string over {a,b}: ");
    scanf("%99s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            printf("Invalid symbol '%c' in the input\n", s[i]);
            return 1;
        }
        int next = delta[state][s[i] - 'a'];
        printf("  delta(q%d, %c) = q%d\n", state, s[i], next);
        state = next;
    }

    if (state == final_state)
        printf("The string %s is ACCEPTED\n", s);
    else
        printf("The string %s is REJECTED\n", s);
    return 0;
}

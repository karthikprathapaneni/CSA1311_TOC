/* Experiment 2: DFA simulation - strings over {0,1} that start with 0 and end with 1 */
#include <stdio.h>

int main(void)
{
    /* States: 0 = start, 1 = started with 0 and last symbol is 0,
       2 = started with 0 and last symbol is 1 (final), 3 = dead (started with 1) */
    int delta[4][2] = {
        /*        0  1 */
        /* q0 */ {1, 3},
        /* q1 */ {1, 2},
        /* q2 */ {1, 2},
        /* q3 */ {3, 3}
    };
    int final_state = 2;
    char s[100];
    int state = 0, i;

    printf("Enter a string over {0,1}: ");
    scanf("%99s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != '0' && s[i] != '1') {
            printf("Invalid symbol '%c' in the input\n", s[i]);
            return 1;
        }
        int next = delta[state][s[i] - '0'];
        printf("  delta(q%d, %c) = q%d\n", state, s[i], next);
        state = next;
    }

    if (state == final_state)
        printf("The string %s is ACCEPTED\n", s);
    else
        printf("The string %s is REJECTED\n", s);
    return 0;
}

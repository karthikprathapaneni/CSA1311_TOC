/* Experiment 4: NFA simulation - strings over {0,1} that start with 0 and end with 1.
   A set of NFA states is stored as a bit mask: bit i is 1 when state qi is active. */
#include <stdio.h>

#define NSTATES 3

static void print_set(int mask)
{
    int i, first = 1;
    printf("{");
    for (i = 0; i < NSTATES; i++)
        if (mask & (1 << i)) {
            printf("%sq%d", first ? "" : ",", i);
            first = 0;
        }
    printf("}");
}

int main(void)
{
    /* q0 --0--> q1; q1 loops on 0,1; q1 --1--> q2 (final) */
    int delta[NSTATES][2] = {
        /*            0                  1                  */
        /* q0 */ {1 << 1,            0},
        /* q1 */ {1 << 1,            (1 << 1) | (1 << 2)},
        /* q2 */ {0,                 0}
    };
    int final_mask = 1 << 2;
    char s[100];
    int current = 1 << 0, i, q;

    printf("Enter a string over {0,1}: ");
    scanf("%99s", s);

    printf("  start: ");
    print_set(current);
    printf("\n");
    for (i = 0; s[i] != '\0'; i++) {
        int next = 0;
        if (s[i] != '0' && s[i] != '1') {
            printf("Invalid symbol '%c' in the input\n", s[i]);
            return 1;
        }
        for (q = 0; q < NSTATES; q++)
            if (current & (1 << q))
                next |= delta[q][s[i] - '0'];
        current = next;
        printf("  after %c: ", s[i]);
        print_set(current);
        printf("\n");
    }

    if (current & final_mask)
        printf("The string %s is ACCEPTED\n", s);
    else
        printf("The string %s is REJECTED\n", s);
    return 0;
}

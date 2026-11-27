/* Experiments 10 and 11: epsilon-closure of every state of an NFA with epsilon-moves.
   Input : number of states n, number of epsilon-transitions m, then m pairs "from to".
   Output: epsilon-closure of each state q0 .. q(n-1).                                   */
#include <stdio.h>

#define MAXN 20

int eps[MAXN][MAXN];      /* eps[i][j] = 1 if there is an epsilon-move qi -> qj */
int visited[MAXN];

/* depth-first search: mark every state reachable from 'state' through epsilon-moves */
static void closure(int state, int n)
{
    int j;
    visited[state] = 1;
    for (j = 0; j < n; j++)
        if (eps[state][j] && !visited[j])
            closure(j, n);
}

int main(void)
{
    int n, m, i, j, from, to;

    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the number of epsilon-transitions: ");
    scanf("%d", &m);
    printf("Enter each epsilon-transition as: from to\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &from, &to);
        if (from < 0 || from >= n || to < 0 || to >= n) {
            printf("State numbers must be between 0 and %d\n", n - 1);
            return 1;
        }
        eps[from][to] = 1;
    }

    printf("\nEpsilon-closures:\n");
    for (i = 0; i < n; i++) {
        int first = 1;
        for (j = 0; j < n; j++)
            visited[j] = 0;
        closure(i, n);
        printf("e-closure(q%d) = {", i);
        for (j = 0; j < n; j++)
            if (visited[j]) {
                printf("%sq%d", first ? "" : ", ", j);
                first = 0;
            }
        printf("}\n");
    }
    return 0;
}

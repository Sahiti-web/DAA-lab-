#include <stdio.h>

#define MAX 100
#define INF 9999

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n;
    int cost[MAX][MAX];
    int i, j, a, b, u, v, min;
    int ne = 1;
    int mincost = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (ne < n) {
        min = INF;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (u != v) {
            printf("Edge %d:(%d, %d) cost:%d\n", ne++, a, b, min);
            mincost += min;
            union_set(u, v);
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost= %d\n", mincost);

    return 0;
}

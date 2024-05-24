#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int dist[10000];
void DFS(int x)
{
    printf("%d ", x);
    int nrVecini = adj[x].size();

    for (int i = 0; i < nrVecini; i++)
    {
        int vecin = adj[x][i];
        if (dist[vecin] == 0)
        {
            dist[vecin] = dist[x] + 1;
            DFS(vecin);
        }
    }
}
void printGraph(int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d -> ", i);
        int nrVecini = adj[i].size();
        for (int j = 0; j < nrVecini; j++)
        {
            printf("%d, ", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    printGraph(n);

    int v[10];

    int x, y;
    scanf("%d%d", &x, &y);

    dist[x] = 1;
    DFS(x);
}
// N - nr de noduri
// M - nr de muchii
// M muchii, de tip a -> b
// X, Y

// BFS(X, Y) -> nr de pasi de la X la Y
// printGraph() -> afisarea listelor de adiacenta
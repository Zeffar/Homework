#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int dist[10000];
int BFS(int x, int y)
{
    queue<int> qe;
    qe.push(x);
    dist[x] = 1;
    while (!qe.empty())
    {
        int node = qe.front();
        qe.pop();
        int nrVecini = adj[node].size();
        for (int i = 0; i < nrVecini; i++)
        {
            int vecin = adj[node][i];
            // is vecin visited

            if (dist[node]==0)
            {
                // vizitam vecinul
                dist[vecin] = dist[node] + 1;
                if (vecin == y)
                {
                    return dist[vecin]; // distanta pana la y
                }
                else
                {
                    qe.push(vecin);
                }
            }
        }
    }
}
void printGraph();
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
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d ", BFS(x, y));
}
// N - nr de noduri
// M - nr de muchii
// M muchii, de tip a -> b
// X, Y

// BFS(X, Y) -> nr de pasi de la X la Y
// printGraph() -> afisarea listelor de adiacenta
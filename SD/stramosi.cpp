#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
int n, m;
int stramosi[33][250005];
// stramosi[k][i] -> 2^kth ancestor of i

// binary lifting

int main()
{
    ios_base::sync_with_stdio(NULL);
    ifstream f("stramosi.in");
    ofstream g("stramosi.out");

    f >> n >> m;
    n++;
    for (int i = 1; i < n; ++i)
        f >> stramosi[0][i];

    for (int i = 1; i < 33; ++i)
        for (int j = 1; j < n; ++j)
            stramosi[i][j] = stramosi[i - 1][stramosi[i - 1][j]];
            // pt al 2^k lea stramos al lui j,
            // gaseste al 2^(k-1) lea stramos al lui j
            // si apoi al 2^(k-1) lea stramos al stramosului

    for (int i = 0; i < m; ++i)
    {
        int a, b, e{};
        f >> a >> b;
        while (b)
        {
            if (b & 1)
                a = stramosi[e][a];
            ++e;
            b >>= 1;
        }
        g << a << '\n';
    }
    f.close();
    g.close();
    return 0;
}
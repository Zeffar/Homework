#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int T;
int m, n, h, w;
vector<vector<int>> rmq;

int solve()
{
    // for all h x w sub-matrices, compute the
    // gcd between all elements in it
    // if gcd < current gcd_max, terminate early
    int gcd_max = 0;
    int gcd_submat;
    for (int l1 = 0; l1 < m - h + 1; ++l1)
        for (int c1 = 0; c1 < n - w + 1; ++c1)
        {
            gcd_submat = rmq[l1][c1];
            for (int i = l1; i < l1 + h - 1 && gcd_submat > gcd_max; ++i)
                for (int j = c1; j < c1 + w - 1 && gcd_submat > gcd_max; ++j)
                    gcd_submat = __gcd(gcd_submat, rmq[i][j]);

            gcd_max = max(gcd_max, gcd_submat);
        }

    return gcd_max;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    f >> T;
    for (int i = 1; i <= T; ++i)
    {
        f >> m >> n >> h >> w;

        rmq.resize(m);
        for (int i = 0; i < m; ++i)
            rmq[i].resize(n);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                f >> rmq[i][j];

        g << "Case #" << i << ": " << solve() << "\n";
    }

    f.close();
    g.close();
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
int n, q, rmq[15][510][510], Log[510];
int main()
{
    ios_base::sync_with_stdio(NULL);
    ifstream f("plantatie.in");
    ofstream g("plantatie.out");
    // range max query 2D
    // rmq[k][i][j] -> max el in subgrid 2^k x 2^k
    //                 incepand din (i, j)
    f >> n >> q;
    ++n;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            f >> rmq[0][i][j];

    for (int k = 1, L = 2; L < n; L *= 2, ++k)
    {
        // pt fiecare putere a lui 2, calculeaza toate
        // val din rmq k = log(L)
        int bound = n - L + 1;
        for (int i = 1; i < bound; ++i)
            for (int j = 1; j < bound; ++j)
            {
                int newI = i + L / 2;
                int newJ = j + L / 2;
                rmq[k][i][j] = max({rmq[k - 1][i][j], rmq[k - 1][newI][newJ], rmq[k - 1][i][newJ], rmq[k - 1][newI][j]});
            }
    }
    for (int i = 2; i < n; ++i)
        Log[i] = Log[i / 2] + 1;

    for (; q--;)
    {
        int i, j, l;
        f >> i >> j >> l;
        int k = Log[l];
        int len = (1 << k);
        int newI = i + l - len;
        int newJ = j + l - len;
        g << max({rmq[k][i][j], rmq[k][i][newJ], rmq[k][newI][j], rmq[k][newI][newJ]}) << '\n';
    }
    f.close();
    g.close();
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    ifstream f("kami.in");
    ofstream g("kami.out");
    const int maxVal = 1e9;
    int n, m;
    f >> n;
    ++n;
    vector<int> rank(n);
    for (int i = 1; i < n; ++i)
        f >> rank[i];

    f >> m;

    bool req;
    int idx, value;
    while (m--)
    {
        f >> req;
        if (!req)
        {
            f >> idx >> value;
            rank[idx] = value;
        }
        else
        {
            f >> idx;
            int sum = rank[idx--];
            while (idx > 0 && sum > rank[idx])
            {
                sum += rank[idx--];
                if (sum > maxVal)
                    idx = 0;
            }
            g << idx << "\n";
        }
    }
    return 0;
    f.close();
    g.close();
    return 0;
}
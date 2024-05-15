#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
struct range
{
    int cost, dr;
};
bool minCmp(range a, range b)
{
    return a.cost > b.cost;
}

bool drCmp(range a, range b)
{
    if (a.dr == b.dr)
        return a.cost < b.cost;
    return a.dr > b.dr;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    ifstream f("timbre.in");
    ofstream g("timbre.out");

    int n, m, k;
    f >> n >> m >> k;

    range aux;
    priority_queue<range, vector<range>, bool (*)(range, range)> pq(minCmp);
    vector<range> v;
    for (int i{}; i < m; ++i)
    {
        f >> aux.dr >> aux.cost;
        v.push_back(aux);
    }

    sort(v.begin(), v.end(), drCmp);
    int i{}, cost{};
    while (n > 0)
    {
        while (v[i].dr >= n && i < m)
            pq.push(v[i++]);
        range cheapest = pq.top();
        cost += cheapest.cost;
        n -= k;
        pq.pop();
    }

    g << cost;

    f.close();
    g.close();
    return 0;
}
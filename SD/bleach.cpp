#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    ifstream f("bleach.in");
    ofstream g("bleach.out");

    long long n, k, x;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    f >> n >> k;
    ++k;
    for (long long i{}; i < k; ++i)
    {
        // first k souls inserted
        f >> x;
        pq.push(x);
    }

    long long ichigo{}, spirit, delta{};
    for (long long i = k; i < n; ++i)
    {
        // fight only the weakest soul in the heap
        // always k souls left in the heap
        spirit = pq.top();
        pq.pop();
        f >> x;
        pq.push(x);

        if (ichigo < spirit)
        {
            delta += spirit - ichigo;
            ichigo = spirit;
        }
        ichigo += spirit;
    }
    f.close();
    while (!pq.empty())
    {
        // fight the remaining k souls
        spirit = pq.top();
        pq.pop();
        if (ichigo < spirit)
        {
            delta += spirit - ichigo;
            ichigo = spirit;
        }
        ichigo += spirit;
    }
    g << delta;
    g.close();
    return 0;
}
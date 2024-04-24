#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
ifstream f("input.txt");
ofstream g("output.txt");

int n, m, x, y, F, aux, s, nrCuv;
char l;
unordered_map<int, bool> isEnd;
unordered_map<int, vector<pair<int, char>>> v;
unordered_map<int, int> dist;

string find(const string &cuv)
{

    queue<int> qe;
    qe.push(s);
    int N = cuv.length();
    dist[s] = 0;
    while (!qe.empty())
    {
        aux = qe.front();
        qe.pop();

        l = cuv[dist[aux]];
        for (auto it : v[aux])
        {
            if (it.second == l)
            {

                qe.push(it.first);
                dist[it.first] = dist[aux] + 1;
                
                if (dist[it.first] == N && isEnd[it.first])
                    return "DA\n";
            }
        }
    }
    return "NU\n";
}

int main()
{
    f >> n;

    for (int i{}; i < n; ++i)
    {
        f >> aux;
        isEnd[aux] = 0;
        dist[aux] = -1;
    }
    f >> m;
    for (int i{}; i < m; ++i)
    {
        f >> x >> y >> l;
        v[x].push_back({y, l});
    }
    f >> s >> F;

    for (int i{}; i < F; ++i)
    {
        f >> aux;
        isEnd[aux] = 1;
    }
    f >> nrCuv;
    for (int i{}; i < nrCuv; ++i)
    {
        string cuv;
        for (auto it : dist)
            dist[it.first] = -1;
        f >> cuv;
        g << find(cuv);
    }
}

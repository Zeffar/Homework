#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
ifstream f("input.txt");
ofstream g("output.txt");

int n, m, x, y, F, aux, s, nrCuv;
char l;
unordered_map<int, bool> isEnd;
unordered_map<int, vector<pair<int, char>>> v;

void convertNFAtoDFA()
{
    map<set<int>, unordered_map<char, set<int>>> dfaTransitions;
    queue<set<int>> q;
    set<set<int>> seenStates;

    set<int> startState = {s};
    cout << s << "\n";
    q.push(startState);
    seenStates.insert(startState);

    while (!q.empty())
    {
        set<int> currentState = q.front();
        q.pop();

        unordered_set<char> alphabet;
        for (int state : currentState)
        {
            for (auto &trans : v[state])
            {
                alphabet.insert(trans.second);
            }
        }
        for (char c : alphabet)
        {
            set<int> newState;
            for (int state : currentState)
            {
                for (auto &trans : v[state])
                {
                    if (trans.second == c)
                    {
                        newState.insert(trans.first);
                    }
                }
            }
            if (!newState.empty())
            {
                dfaTransitions[currentState][c] = newState;
                if (seenStates.find(newState) == seenStates.end())
                {
                    q.push(newState);
                    seenStates.insert(newState);
                }
            }
        }
    }

    for (auto &state : dfaTransitions)
    {

        for (auto &trans : state.second)
        {
            for (int s : state.first)
                g << s << ",";
            g << " -" << trans.first << "-> ";
            for (int s : trans.second)
                g << s << ",";
            g << endl;
        }
    }
}

int main()
{
    f >> n;

    for (int i{}; i < n; ++i)
    {
        f >> aux;
        isEnd[aux] = 0;
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
    convertNFAtoDFA();
}

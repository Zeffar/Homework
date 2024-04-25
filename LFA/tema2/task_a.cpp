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
class NFA
{
private:
    int s;
    unordered_map<int, bool> isEnd;
    unordered_map<int, vector<pair<int, char>>> v;

public:
    NFA() : s(0){};

    void setStart(int start)
    {
        s = start;
    }

    void setEnd(int x, bool endValue)
    {
        isEnd[x] = endValue;
    }

    void addEdge(int from, int to, char letter)
    {
        v[from].push_back({to, letter});
    }

    void toDFA()
    {

        NFA DFA;

        queue<int> q;


        set<int> seenStates;

        // Initialize the DFA with the start state of the NFA.
        q.push(s);

        seenStates.insert(s);

        // Process each set of states in the queue until there are no more new states.
        while (!q.empty())
        {

            int currentState = q.front();
            q.pop();
            unordered_set<char> alphabet;
            for (const auto &state : v[currentState])
            {
                alphabet.insert(state.second);
            }

            // For each character in the alphabet, determine the new set of NFA states
            // that can be reached from the current DFA state using this character.
            for (char c : alphabet)
            {
                int newState = -1;

                for (auto &trans : v[currentState])
                {
                    if (trans.second == c)
                    {
                        newState = trans.first;
                    }
                }

                // If the new state set formed is not empty and has not been seen before,
                // it's added to the queue for processing and to the map of DFA transitions.
                if (newState != -1)
                {
                    DFA.v[currentState].push_back({newState, c});
                    if (seenStates.find(newState) == seenStates.end())
                    {
                        q.push(newState);
                        seenStates.insert(newState);
                    }
                }
            }
        }
        for(const auto &node : v) 
        {
            for(const auto & adj: node.second) {
                cout<<node.first<<" "<<adj.second<<" "<<adj.first<<'\n';
            } 
        }
    }
};

int main()
{
    ifstream f("input.txt");

    int n;
    f >> n;
    NFA nfa;
    for (int i{}; i < n; ++i)
    {
        int aux;
        f >> aux;
        nfa.setEnd(aux, false);
    }
    int m;
    f >> m;
    for (int i{}; i < m; ++i)
    {
        int x, y;
        char l;
        f >> x >> y >> l;
        nfa.addEdge(x, y, l);
    }
    int s, F;
    f >> s >> F;
    nfa.setStart(s);
    for (int i{}; i < F; ++i)
    {
        int aux;
        f >> aux;
        nfa.setEnd(aux, true);
    }
    nfa.toDFA();
}
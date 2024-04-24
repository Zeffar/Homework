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
class NFA // can be DFA too
{
private:
    int n, s;
    char l;
    unordered_map<int, bool> isEnd;
    unordered_map<int, vector<pair<int, char>>> v;

public:
    NFA(int N) : n(N){};
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

        // Map to store DFA transitions. Each state in the DFA is a set of NFA states,
        // and it maps an input character to another set of NFA states (DFA state).
        map<set<int>, unordered_map<char, set<int>>> dfaTransitions;

        // Queue to manage the set of states currently being processed.
        queue<set<int>> q;

        // Set to keep track of seen DFA states to avoid reprocessing the same states.
        set<set<int>> seenStates;

        // Initialize the DFA with the start state of the NFA.
        set<int> startState = {s};
        q.push(startState);

        seenStates.insert(startState);

        // Process each set of states in the queue until there are no more new states.
        while (!q.empty())
        {

            set<int> currentState = q.front();
            q.pop();

            // Collect all characters leading out of the current state set. This forms
            // the effective alphabet for the transitions from this state.
            unordered_set<char> alphabet;
            for (int state : currentState)
            {
                for (auto &trans : v[state])
                {

                    alphabet.insert(trans.second);
                }
            }

            // For each character in the alphabet, determine the new set of NFA states
            // that can be reached from the current DFA state using this character.
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

                // If the new state set formed is not empty and has not been seen before,
                // it's added to the queue for processing and to the map of DFA transitions.
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

        ofstream g("output.txt");
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
};

int main()
{
    ifstream f("input.txt");

    int n;
    f >> n;
    NFA nfa(n);
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
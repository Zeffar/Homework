// Bzorkowski
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
class DFA
{
private:
    int startState;
    set<int> acceptingStates;
    // a --l--> b
    unordered_map<int, vector<pair<int, char>>> transitions;

public:
    DFA() : startState(0) {}

    void setStart(int start)
    {
        startState = start;
    }

    void addEdge(int from, int to, char input)
    {
        transitions[from].push_back({to, input});
    }

    void setEnd(int state)
    {
        acceptingStates.insert(state);
    }

    void print(string path)
    {
        ofstream g(path);
        for (const auto &node : transitions)
        {
            for (const auto &adj : node.second)
            {
                g << node.first << " -" << adj.second << "-> " << adj.first << '\n';
            }
        }
        g << "starting state: ";
        g << startState << '\n';
        g << "accepting states: ";
        for (const auto &state : acceptingStates)
        {
            g << state << ' ';
        }
    }

    void reverse()
    {
        DFA reversedDFA;
        for (const auto &node : transitions)
        {
            for (const auto &adj : node.second)
            {
                // reversedDFA.addEdge(adj.first, node.first, adj.second);
                reversedDFA.transitions[adj.first].push_back({node.first, adj.second});
            }
        }
        int newNode = -1;
        for (const auto &state : acceptingStates)
        {
            reversedDFA.transitions[newNode].push_back({state, '_'});
        }
        reversedDFA.startState = newNode;
        reversedDFA.acceptingStates.insert(startState);

        startState = reversedDFA.startState;
        acceptingStates = reversedDFA.acceptingStates;
        transitions = reversedDFA.transitions;
    }

    void subset()
    {

        DFA newDFA;

        queue<int> q;

        set<int> seenStates;

        // Initialize the DFA with the start state of the NFA.
        q.push(startState);

        seenStates.insert(startState);

        // Process each set of states in the queue until there are no more new states.
        while (!q.empty())
        {

            int currentState = q.front();
            q.pop();
            unordered_set<char> alphabet;
            for (const auto &state : transitions[currentState])
            {
                alphabet.insert(state.second);
            }

            // For each character in the alphabet, determine the new set of NFA states
            // that can be reached from the current DFA state using this character.
            for (char c : alphabet)
            {
                int newState = -1;

                for (auto &trans : transitions[currentState])
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
                    newDFA.transitions[currentState].push_back({newState, c});
                    if (seenStates.find(newState) == seenStates.end())
                    {
                        q.push(newState);
                        seenStates.insert(newState);
                    }
                }
            }
        }
        transitions = newDFA.transitions;

    }
};

int main()
{
    ifstream f("input.txt");

    int n;
    f >> n;
    DFA dfa;
    for (int i{}; i < n; ++i)
    {
        int aux;
        f >> aux;
    }

    int m;
    f >> m;
    for (int i{}; i < m; ++i)
    {
        int x, y;
        char l;
        f >> x >> y >> l;
        dfa.addEdge(x, y, l);
    }
    int s, F;
    f >> s >> F;
    dfa.setStart(s);
    for (int i{}; i < F; ++i)
    {
        int aux;
        f >> aux;
        dfa.setEnd(aux);
    }
    // dfa.print("output.txt");

    dfa.reverse();
    dfa.subset();
    dfa.reverse();
    dfa.subset();
    dfa.print("output.txt");
    return 0;
}

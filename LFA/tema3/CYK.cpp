#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
using namespace std;

void cyk(const vector<string> w, const unordered_map<string, vector<vector<string>>> &rule)
{
    int n = (int)w.size();
    map<int, map<int, set<string>>> T;
    for (int j = 0; j < n; j++)
    {
        for (const auto &x : rule)
        {
            string lhs = x.first;
            vector<vector<string>> rule = x.second;

            for (const auto &rhs : rule)
                // if terminal
                if (rhs.size() == 1 && rhs[0] == w[j])
                    T[j][j].insert(lhs);
        }

        for (int i = j; i >= 0; i--)
            for (int k = i; k <= j; k++)
                for (const auto &x : rule)
                {
                    string lhs = x.first;
                    vector<vector<string>> rule = x.second;

                    for (const auto &rhs : rule)
                        // if terminal
                        if (rhs.size() == 2 && T[i][k].find(rhs[0]) != T[i][k].end() && T[k + 1][j].find(rhs[1]) != T[k + 1][j].end())
                            T[i][j].insert(lhs);
                }
    }

    // if word can be formed
    if (T[0][n - 1].size() != 0)
        cout << "Valid\n";
    else
        cout << "Invalid\n";
}

int main()
{
    unordered_map<string, vector<vector<string>>> rule;
    rule["A"] = {{"D", "B"}};
    rule["B"] = {{"C", "B"}, {"s"}, {"ss"}, {"sss"}};
    rule["C"] = {{"E", "F"}, {"a"}, {"aa"}, {"aaa"}};
    rule["D"] = {{"i"}};
    rule["E"] = {{"c"}, {"cc"}};
    rule["F"] = {{"b"}, {"bb"}, {"bbb"}, {"bbbb"}};

    vector<string> w;

    w = {"i", "cc", "b", "s"};
    cyk(w, rule);

    w = {"i", "cc", "sss", "bb"};
    cyk(w, rule);

    return 0;
}

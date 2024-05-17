#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#if 0
ifstream f("in");
ofstream g("out");
#define cin f
#define cout g
#endif // 1

vector<int> tree[101];

void gen_tree(size_t n)
{
    for (size_t i : tree[n])
    {
        cout << "IF fork() THEN\n";
        gen_tree(i);
        cout << "ELSE\n";
    }
    for (size_t _ : tree[n])
        cout << "ENDIF\n";
}

size_t n;

int main()
{
    cin >> n;
    int a, b;
    for (size_t i = 1; i < n; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
    }
    gen_tree(0);
    cout.flush();
    return 0;
}
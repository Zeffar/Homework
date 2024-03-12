#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int>v[101];
int viz[101];

void DFS(int node) {
    cout<<node<<" ";
    viz[node] = 1;
    for (int adj : v[node]) {
        if(!viz[adj]) {
            DFS(adj);
            viz[adj] = 2;
        }
    }
}

void BFS(int start, int end) {
    queue<int> qe;
    viz[start] = 1;
    qe.push(start);
    while(!qe.empty()) {
        int currentNode = qe.front();
        qe.pop();

        for( int adj : v[currentNode]) {
            if(!viz[adj]) {
                viz[adj] = 1 + viz[currentNode];
                if(adj == end) {cout<<viz[adj]-1; return;}
                qe.push(adj);
            }
        }
    }
}

int main() {
    ifstream f("text.txt");
    int n, m;
    f>>n>>m;
    
    for(int i=0; i<m; ++i) {
        int a, b; f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    BFS(3, 1);
    cout<<'\n';
    for(int i=1; i<=n; ++i)
        cout<<viz[i]-1<<" ";
    cout<<'\n';

    return 0;

}

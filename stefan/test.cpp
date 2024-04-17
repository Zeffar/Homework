#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int v[100];
    for(int i = 0; i < 100; i++) {
        v[i] = i;
    }
    for(int it : v) {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

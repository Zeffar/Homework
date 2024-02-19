#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin>>n>>k; cin.ignore();
    vector<int> v(n);
    int rez{};
    for( int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int dr = n-1;
    for (int i = 0; i <= dr; ++i) {
        if(v[i] + v[dr] <= k) dr--;
        rez++;
    }
    cout<<rez<<'\n';
}
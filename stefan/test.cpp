#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    if (n < 4)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }

    int aux = 2;
    for (int i = 2; i <= n; i += 2)
    {
        printf("%d ", i);
    }

    int v[100];
    cout << v[1] << " " << v[3] << " " << v[19] << '\n';
    printf("%d %d %d\n", v[1], v[3], v[19]);
    aux = 1;
    for (int i = 1; i <= n; i += 2)
    {
        printf("%d ", i);
    }
    cout << '\n';
    return 0;
}

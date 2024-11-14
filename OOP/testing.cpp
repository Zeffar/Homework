
#include <iostream>
using namespace std;
template <class X>
int functie(X *x, int y)
{
    return x + y;
}
int functie(int *x, int y)
{
    return *(x - 100*y);
}
int main()
{
    int *a = new int(45), b = 27;
    cout << functie(a, b);
    return 0;
}
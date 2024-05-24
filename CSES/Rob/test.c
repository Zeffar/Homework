#include <stdio.h>

int main()
{
    int *a;
    char *b;
    int nr = 100;
    printf("%d\n", nr);
    a = &nr;
    printf("Adresa lui nr -> %d\n", a);
    printf("%d\n", *a);
}

1 2 3 4 5 6 7   8 9
  7         100   
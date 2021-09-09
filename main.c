#include <stdio.h>
#include "Header.h"


int main()
{
    double x1 = 0, x2 = 0;
    double a=0, b=0, c=0;

    int n = scanf("%lg %lg %lg", &a, &b, &c);
    check_value(n, a, b, c);

    int res = nRoots(a, b, c, &x1, &x2);
    num_print(res);

    return 0; 
}

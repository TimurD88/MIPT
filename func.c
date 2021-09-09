#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Header.h"


double EPS = 1e-6;
int NUM_INPUT = 3;

void num_print(int res)
{
    switch(res)
    {
        case(0):
            printf("Zero");
            break;
        case(1):
            printf("Once");
            break;
        case(2):
            printf("Twice");
            break;
        case(INFINITE_SOLUTION):
            printf("INFINITE");
            break;
        case(COMPLEX_NUM):
            printf("Complext nums");
            break;
        default:
            printf("ERROR, number of solutions = %d\n", res);
    }
}

int is_zero(double m)
{
    if ( fabs(m) < EPS)
        return 1;
    return 0;
}

int nRoots(double a, double b, double c, double * x1, double * x2)
{
    assert( x1 != NULL );
    assert( x2 != NULL );
    assert( x1 != x2 );

    if ( is_zero(a) == 1 )
    {
        if ( is_zero(b) == 1 )
        {
            if ( is_zero(c) == 1 ) 
                return INFINITE_SOLUTION;
            
            return 0;
        }
        *x1 = (-c)/b;
        return 1;
    }
    else
    {
        double discr = (b * b - 4 * a * c);
        if ( discr < 0 )
            return -1;
        else if ( is_zero(discr) == 1 )
        {
            *x1 = -b / (2 * a);
            *x2 = *x1;
            return 1;
        }
        double discr_sqrt = sqrt(discr);
        *x1 = (-b + discr_sqrt) / (2 * a);
        *x2 = (-b - discr_sqrt) / (2 * a);
        return 2;
    }


}

void check_value( int n, double a, double b, double c )
{
    int i = 0;

    assert( isinf( a ) == 0 );
    assert( isinf( b ) == 0 );
    assert( isinf( c ) == 0 );

    if ( n != NUM_INPUT )
    {
        printf("Not enought number of input");
        while ( i != NUM_INPUT) 
        {
            i = scanf("%lg %lg %lg", &a, &b, &c);
        }
    }
}
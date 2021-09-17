#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Header.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


static const double EPS = 1e-6;
static int NUM_INPUT = 3;

double get_num(char * text)
{
    char buf[BUFFER_SIZE];
    printf("%s",text);
    char * p = fgets (buf, BUFFER_SIZE, stdin);
    //printf("%p\n", p);
    if ( p == NULL )
    	return NAN;
    else 
    {
	    if (!isdigit(buf[0]) && buf[0] != '-')
	    {
	    	printf("Incorrect!\n");	
	    	return NAN;
    	}
    		
    	for ( int i = 0; i < strlen(buf); i++)
       	{
        	if ( isalpha (buf[i]))
        		{
        		    printf("Incorrect!\n");
        		    return NAN;	    
        		}    
 		}
 	}
    double res = atof(buf);
    //fflush(stdin);
    return res;
     
}


void num_print(int res)
{
    switch(res)
    {
        case(ZERO):
            printf("Zero");
            break;
        case(ONE):
            printf("Once");
            break;
        case(TWO):
            printf("Twice");
            break;
        case(INFINITE):
            printf("INFINITE_NUMBER_OF_SOLUTIONS");
            break;
        case(COMPLEX):
            printf("Complext nums");
            break;
        default:
            printf("ERROR, number of solutions = %d\n", res);
    }
}

int is_equal( double a, double b )
{
	if ( fabs(a - b) < EPS )
		return 1; 
	return 0;
}

int eq_solver(double a, double b, double c, double * x1, double * x2)
{
	assert( !isnan(a) );
	assert( !isnan(b) );
	assert( !isnan(c) );
    assert( x1 != NULL );
    assert( x2 != NULL );
    assert( x1 != x2 );
	/*
	if ( is_equal(a, b) && is_equal(b, c) )
	{
		char str1 = a + '0';
		if ( str1 == '0')
			return INFINITE;
		return COMPLEX;
	}*/
	
    if ( is_equal(a, 0) )
    {
        if ( is_equal(b, 0) == 1 )
        {
            if ( is_equal(c, 0) == 1 ) 
                return INFINITE;
            
            return ZERO;
        }
        *x1 = (-c)/b;
        return ONE;
    }
    else
    {
        double discr = (b * b - 4 * a * c);
        if ( discr < 0 )
            return COMPLEX;
        else if ( is_equal(discr, 0) == 1 )
        {
            *x1 = -b / (2 * a);
            *x2 = *x1;
            return ONE;
        }
        double discr_sqrt = sqrt(discr);
        *x1 = (-b + discr_sqrt) / (2 * a);
        *x2 = (-b - discr_sqrt) / (2 * a);
        return TWO;
    }


}


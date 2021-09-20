#include <stdio.h>
#include "test.h"
#include "func.h"


int Test_function(const char* name, int expression)
{
	if (expression)
	{
		printf("test %s passed\n", name);
		return 1;
	}
	else
	{
		printf("test %s failed\n", name);
		return 0;
	}
}



void test_unit(void)
{
	printf("Unit tests:\n");

	double x1 = 0, x2 = 0;

	int number_tests_passed = 0, number_tests_failed = 0;

#define TEST(name, expression) ((Test_function(name, expression)) ? ++number_tests_passed : ++number_tests_failed)

	TEST("infinite number of roots",
		eq_solver(0, 0, 0, &x1, &x2) == INFINITE);
	TEST("0 roots, constant equation",
		eq_solver(0, 0, 1, &x1, &x2) == 0);
	TEST("0 roots, quadratic equation",
		eq_solver(1, 1, 1, &x1, &x2) == COMPLEX);
	TEST("1 root, linear equation, number of roots",
		eq_solver(0, 1, 1, &x1, &x2) == 1);
	TEST("complex roots",
		eq_solver(0.0000000000000001, 0.0000000000000001, 0.0000000000000001, &x1, &x2) == INFINITE);
	TEST("2 roots, quadratic equation",
		eq_solver(1, 1, 0, &x1, &x2) == 2);
	TEST("2 roots, quadratic equation",
		eq_solver(1, 3, 1, &x1, &x2) == 2);

#undef TEST

	printf("Finished testing Count_and_solve_quadratic_equation function: %d tests passed, %d tests failed. The"
		"total number of tests was: %d\n",
		number_tests_passed, number_tests_failed, number_tests_passed + number_tests_failed);
}


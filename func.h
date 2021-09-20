

enum TypesSolveSquare
{
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	COMPLEX = -1,
	INFINITE = -2,
	BUFFER_SIZE = 24
};

//! Checks, that input is correct
double get_num(char * text);

//! prints num of roots
void num_print(int res);

//! solves and finds num of roots
int eq_solver(double a, double b, double c, double * x1, double * x2);



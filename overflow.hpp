#include <cstdlib>
#include <iostream>
#include <cmath>
#include <climits>
#include <fstream>

using namespace std;

/* Primary Functions */
// used function overloading : so that user will be able to call the "same" function regardless
// of whether they want to perform operations on integers or doubles
int factorial ( int x );
double factorial ( double x );

int fibonacci ( int sequence );
double fibonacci( double sequence );

/* Test Functions */
bool test_factorial_int();
bool test_factorial_int_error();
bool test_factorial_int_overflow();

bool test_factorial_double();
bool test_factorial_double_error();
bool test_factorial_double_overflow();

bool test_fibonacci_int();
bool test_fibonacci_int_error();
bool test_fibonacci_int_overflow();

bool test_fibonacci_double();
bool test_fibonacci_double_error();
bool test_fibonacci_double_overflow();

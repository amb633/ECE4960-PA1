#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

/* Primary Functions */
bool equals( double x , double y );
double subtract( double x , double y );
double divide( double x , double y );
double sine_fcn( double x );

/* Test Functions */
bool test_subtraction();
bool test_divide();
bool underflow_via_subtraction();
bool underflow_via_division();
bool underflow_via_sine();

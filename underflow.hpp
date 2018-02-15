#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

/* Primary Functions */
void subtract( double x , double y , double& d , bool& u );
void divide( double x , double y , double& d , bool& u );
void sine_fcn( double x , double& d , bool& u );

/* Test Functions */
bool test_subtraction();
bool test_divide();
bool underflow_via_subtraction();
bool underflow_via_division();
bool underflow_via_sine();

#include "underflow.hpp"
/* Primary Underflow Functions */


void subtract( double x , double y , double& d , bool& u ) {
	// perform the subtraction
	d = x - y;
	// check if underflow has occurred, and return true or false appropriately
	u = false;
	if ( (d+y) != x ) u = true;
	return;
}

void divide( double x , double y , double& d , bool& u ) {
	// perform the division
	d = x/y;
	// check if underflow has occurred, and return true or false appropriately
	u = false;
	if ( (d*y) != x ) u = true;
	return;
}

void sine_fcn( double x , double& d , bool& u ) {
	// perform the sinc calculation
	double y = sin(1.23456789012345*x);
	d = y/x;
	// check if underflow has occurred, and return true or false appropriately
	u = false;
	if ( (asin(d*x))/1.23456789012345 != x ) u = true;
	return;
}
#include "underflow.hpp"

void subtract( double x , double y , double& d , bool& u ) {
	d = x - y;
	u = false;
	if ( (d+y) != x ) u = true;
	return;
}

void divide( double x , double y , double& d , bool& u ) {
	d = x/y;
	u = false;
	if ( (d*y) != x ) u = true;
	return;
}

void sine_fcn( double x , double& d , bool& u ) {
	double y = sin(1.23456789012345*x);
	d = y/x;
	u = false;
	if ( (asin(d*x))/1.23456789012345 != x ) u = true;
	return;
}
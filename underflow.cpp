#include "underflow.hpp"

bool equals( double x , double y ) {
	if ( x == y ) return true;
	else return false;
}

double subtract( double x , double y ) {
	return ( x - y );
}

double divide( double x , double y ) {
	return ( x/y );
}

double sine_fcn( double x ) {
	double y = sin(1.23456789012345*x);
	return ( y/x );
}
#include "notanumber.hpp"

/* Primary Functions */

// Generate nan by square rooting a negative number 
double sqrtNegative( double x ) {
	return sqrt(-abs(x));
}

// Generate nan by taking the lpog of a negative number
double logNegative ( double x ) {
	return log(-abs(x));
}

// Generate nan by taking inf less inf
double infLessInf () {
	// first generate inf
	double inf = 4.0/0.0;
	// then generate nan
	return (inf - inf);
}

// Generate nan by taking inf divided by inf
double infDivideInf() {
	//first generate inf
	double inf = 2.0/0.0;
	// then generate nan
	return inf/inf;
}

/* Secondary Arithmetic Functions */
double addNan( double x , double y ) {
	return x + y;
}
double multiplyNan( double x , double y ) {
	return x*y;
}
double sineNan( double x ) {
	return sin(x);
}
double powerNan( double x , double y) {
	return pow( x , y );
}
// calculate the sum of inf and nan
double infAndNan(){
	//first generate inf
	double inf = 3.0/0.0;
	//second generate nan
	double nan = sqrt(-1);
	//then add them
	return (inf+nan);
}

/* Custom function ot detect nan */
// nan should not return true on any logical comparators, as stipulated by the IEEE standards:
// i.e. nan does not equal a rational number ( e.g. 2.0 )
// nan is not more than a rational number
// nan is not less than a rational number
// if all three checks return a false, then the number is likely a nan > so return true
// if the number is not a nan (i.e. it is a rational number), it will pass one of the three checks > so return a false
bool detectNan( double x ) {
	double y = 2.0;
	if ( !(y == x) && !(y<x) && !(y>x) ) return true;
	else return false;
}
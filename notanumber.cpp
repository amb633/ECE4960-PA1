#include "notanumber.hpp"

double sqrtNegative( double x ) {
	return sqrt(-abs(x));
}

double logNegative ( double x ) {
	return log(-abs(x));
}

double infLessInf () {
	return (INFINITY - INFINITY);
}

double infDivideInf() {
	return INFINITY/INFINITY;
}

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

double infAndNan(){
	return INFINITY + NAN;
}
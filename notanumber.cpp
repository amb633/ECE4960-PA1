#include "notanumber.hpp"

double sqrtNegative( double x ) {
	return sqrt(-abs(x));
}

double logNegative ( double x ) {
	return log(-abs(x));
}

double infLessInf () {
	// first generate inf
	double inf = 4.0/0.0;
	// then generate nan
	return (inf - inf);
}

double infDivideInf() {
	//first generate inf
	double inf = 2.0/0.0;
	return inf/inf;
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
	//first generate inf
	double inf = 3.0/0.0;
	//second generate nan
	double nan = sqrt(-1);
	//then add them
	return (inf+nan);
}

bool detectNan( double x ) {
	double y = 2.0;
	if ( !(y == x) && !(y<x) && !(y>x) ) return true;
	else return false;
}
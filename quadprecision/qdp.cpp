#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

void split( double a , double& a_hi , double& a_lo );
void quick_two_sum( double a , double b , double& s , double& e);
void two_sum( double a , double b , double& s , double& e );
void two_prod( double a , double b , double& p , double& e );
void renormalize( double a0 , double a1 , double a2 , double a3 , double a4 , double& b0 , double& b1 , double& b2 , double& b3 );

int main(int argc, char const *argv[])
{
	cout.precision(30);
	double a = 1.23456789012345*pow(10,10);
	double b = 6.7890123456789012*pow(10,-5);
	double c = 1.2345678901234567890123456789012*pow(10,10);

	double c_hi , c_lo;
	split( c , c_hi , c_lo );
	double s , e;
	quick_two_sum ( a , b , s , e );

	cout << c << " : " << c_hi << " + " << c_lo << " = " << c_hi+c_lo << endl;
	cout << a << " + " << b << " = " << s+e << endl;



	cout << endl;
	return 0;
}

void split( double a , double& a_hi , double& a_lo ) {
	double t = ( pow(2,27) + 1 ) * a;
	a_hi = t - (t-a);
	a_lo = a - a_hi;
	return;
}

void quick_two_sum( double a , double b , double& s , double& e ) {
	double sum = a + b;
	e = b - (sum-a);
	s = sum;
	return;
}

void two_sum( double a , double b , double& s , double& e ) {
	s = a + b;
	double v = s - a;
	e = ( a - (s-v) ) + ( b-v );
	return;
}

void two_prod( double a , double b , double& p , double& e ) {
	p = a*b;
	double a_hi , a_lo , b_hi , b_lo;
	split( a , a_hi , a_lo );
	split( b , b_hi , b_lo );
	e = (( (a_hi*b_hi) - p ) + (a_hi*b_lo) + (a_lo*b_hi) ) + (a_lo*b_lo);
	return;
}

void renormalize( double a0 , double a1 , double a2 , double a3 , double a4 , double& b0 , double& b1 , double& b2 , double& b3 ){

	double s , t4;
	quick_two_sum( a3 , a4 , s , t4 );

	double t3;
	quick_two_sum( a2 , s , s , t3 );

	double t2;
	quick_two_sum( a1 , s , s , t2 );
	double t0 , t1;
	quick_two_sum( a0 , s , t0 , t1 );

	s = t0;

	b0 = 0;
	b1 = 0;
	b2 = 0;
	b3 = 0;

	double e;
	quick_two_sum( s , t0 , s , e );
	if ( e!=0 ) {
		b0 = s;
		s = e;
	}
	quick_two_sum( s , t1 , s , e );
	if ( e!=0 ) {
		b1 = s;
		s = e;
	}
	quick_two_sum( s , t2 , s , e );
	if ( e!=0 ) {
		b2 = s; 
		s = e;
	}
	quick_two_sum( s, t3 , s, e );
	if (e!=0){
		b3 = s;
		s = e;
	}
	return;
}
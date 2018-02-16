#include "underflow.hpp"

// test basic functionality of the subtraction function
bool test_subtraction() {

	double d1 , d2;
	bool u1 , u2;

	subtract( 5 , 3 , d1 , u1 );
	subtract( 10 , 12 , d2 , u2 );

	if ( (d1 == 2) && (d2 == -2) && !u1 && !u2 ) return true;
	else return false;
}

// test basic functionality of the division function
bool test_divide() {
	double d1 , d2;
	bool u1 , u2;

	divide ( 6 , 3 , d1 , u1 );
	divide ( 15 , 10 , d2 , u2 );
	if ( (d1==2) && (d2 == 1.5) && !u1 && !u2 ) return true;
	else return false;
}

// test the underflow of the subtraction function
bool underflow_via_subtraction() {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);

    double result;
    bool under;

	double x = pow(20,-3);
	double y = pow(10,-3);
	full_log << boolalpha;

	for (int i = 0 ; i<20 ; i++){	
		subtract( 1+x , 1+y , result , under );
		full_log << result << endl;
		x /=10;
		y /=10;
	}
    full_log.close();
	return true;
}

// test the underflow of the division function
bool underflow_via_division() {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	double x = 20;
	double y = pow(10,300);
	full_log.precision(10);
	full_log << boolalpha;
	double result;
	bool under;

	for (int i = 0 ; i<20 ; i++ ) {
		divide( 1+x , 1+y , result , under );
		full_log << result << endl;
		y *= 10;
	}
    full_log.close();
	return true;
}

// test hte underflow of the sinc function
bool underflow_via_sine() {
	double x = 1;
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	full_log.precision(30);
	full_log << boolalpha;
	double result;
	bool under;

	for (int i = 0 ; i < 20 ; i++ ) {
		sine_fcn( x , result , under );
		full_log << result << endl;
		x /= 100;
	}
    full_log.close();
	return true;

}

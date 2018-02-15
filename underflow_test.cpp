#include "underflow.hpp"

bool test_subtraction() {
	if (subtract(5,3) == 2 && subtract(10,12) == -2 ) return true;
	else return false;
}

bool test_divide() {
	if (divide(6,3) == 2 && divide(15,10) == 1.5 ) return true;
	else return false;
}

bool underflow_via_subtraction() {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	double x = pow(20,-3);
	double y = pow(10,-3);

	for (int i = 0 ; i<20 ; i++){
		full_log << boolalpha;
		//cout << "x equals y is " << equals( 1+x , 1+y ) << " and ";
		full_log << subtract(1+x , 1+y ) << endl;
		x /=10;
		y /=10;
	}
    full_log.close();
	return true;
}

bool underflow_via_division() {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	double x = 20;
	double y = pow(10,300);
	full_log.precision(10);

	for (int i = 0 ; i<20 ; i++ ) {
		full_log << divide((1+x),(1+y)) << endl;
		y *= 10;
	}
    full_log.close();
	return true;
}

bool underflow_via_sine() {
	double x = 1;
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	full_log.precision(30);

	for (int i = 0 ; i < 20 ; i++ ) {
		full_log << sine_fcn(x) << endl;
		x /= 100;
	}
    full_log.close();
	return true;

}

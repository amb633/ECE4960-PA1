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
	
	double x = pow(20,-3);
	double y = pow(10,-3);

	for (int i = 0 ; i<20 ; i++){
		cout << boolalpha;
		//cout << "x equals y is " << equals( 1+x , 1+y ) << " and ";
		cout << subtract(1+x , 1+y ) << endl;
		x /=10;
		y /=10;
	}
	return true;
}

bool underflow_via_division() {

	double x = 20;
	double y = pow(10,300);
	cout.precision(10);

	for (int i = 0 ; i<20 ; i++ ) {
		cout << divide((1+x),(1+y)) << endl;
		y *= 10;
	}
	return true;
}

bool underflow_via_sine() {
	double x = 1;

	cout.precision(30);

	for (int i = 0 ; i < 20 ; i++ ) {
		cout << sine_fcn(x) << endl;
		x /= 100;
	}
	return true;

}
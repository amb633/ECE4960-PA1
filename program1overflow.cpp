#include "overflow.hpp"

int main() {
	cout << endl;
	cout << boolalpha;

	cout << "integer factorial function working?  " << test_factorial_int() << endl;
	cout << "error test for integer factorial fcn " << test_factorial_int_error() << endl;
	cout << "overflow test for int factorial fcn  " << test_factorial_int_overflow() << endl;

	cout << "double  factorial function working? " << test_factorial_double() << endl;
	cout << "error test for double factorial fcn " << test_factorial_double_error() << endl;
	cout << "overflow test for double factorial  " << test_factorial_double_overflow() << endl;

	cout << "integer fibonacci function working?  " << test_fibonacci_int() << endl;
	cout << "error test for integer fibonacci fcn " << test_fibonacci_int_error() << endl;
	cout << "overflow test for int fibonacci fcn  " << test_fibonacci_int_overflow() << endl;

	cout << "double fibonacci function working?  " << test_fibonacci_double() << endl;
	cout << "error test for double fibonacci fcn " << test_fibonacci_double_error() << endl;
	cout << "overflow test for double fibonacci  " << test_fibonacci_double_overflow() << endl;
	

	cout << endl;
	return 0;
}


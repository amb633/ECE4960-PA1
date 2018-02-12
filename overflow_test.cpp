# include "overflow.hpp"

bool test_factorial_int() {
	// test if the integer factorial function is working
	if ( factorial(3) == 6 && factorial(4) ==24 ) return true;
	else return false;
	
}

bool test_factorial_int_error() {
	// test if passing in negative arguments returns error
	if ( factorial(-1) == -1 && factorial(-10) == -1 ) return true;
	else return false;
}

bool test_factorial_int_overflow() {
	// test if overflow returns error
	if ( factorial(20) == -2 ) return true;
	else return false;
}

bool test_factorial_double() {
	// test if the double factorial function is working
	if ( factorial(3.0) == 6.0 && factorial(4.0) == 24.0 ) return true;
	else return false;
}

bool test_factorial_double_error() {
	// test if passing in negative arguments returns error
	if ( factorial(-5.0) == -1.1 && factorial(-20.0) == -1.1 ) return true;
	else return false;
}

bool test_factorial_double_overflow() {
	// test if double factorial function is overflowing
	if (factorial(200.0) == -2.1) return true;
	else return false;
}

bool test_fibonacci_int() {
	// test if the integer fibonacci function is working 
	if ( fibonacci(5) == 5 && fibonacci(6) == 8 ) return true;
	else return false;
}

bool test_fibonacci_int_error() {
	// test if passing in negative arguments returns error
	if ( fibonacci(-5) == -1 && fibonacci(-10) == -1 ) return true;
	else return false;
}

bool test_fibonacci_int_overflow() {
	// test if integer fibonacci is overflowing
	if ( fibonacci(100) == -2 ) return true;
	else return false;
}

bool test_fibonacci_double() {
	// test if the double fibonacci function is working
	if (fibonacci(5.0) == 5.0 && fibonacci(6.0) == 8.0 ) return true;
	else return false;
}

bool test_fibonacci_double_error() {
	// test if passing in negative arguments returns error
	if (fibonacci(-5.0) == -1.1 && fibonacci(-10.0) == -1.1) return true;
	else return false;
}

bool test_fibonacci_double_overflow() {
	// test if double fibonacci is overflowing
	if ( fibonacci(10000.0) == -2.1 ) return true;
	else return false;
}
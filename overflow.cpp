# include "overflow.hpp"

/* Primary Functions for Integer and Floating Point Overflows */

int factorial ( int x ) {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    // error detection : factorial not defined for x less than 0
	if ( x< 0 ) return -1;
	// if x is 0 , return 0
	if ( x == 0 ) return 0;

	int product = 1;
	int temp;
	// calculate factorial by successive multiplication
	for ( int i = 1 ; i <=x ; i++ ) {
		temp = product*i;
		// at each iteration check if the new number generated is actually the product of the previous two terms
		// by performing a reverse calculation
		if ( temp/i == product )
			// if reverse calculation passed, proceed to next iteration
			product = temp;
		else {
			// if reverse calculation failed, overflow has occurred. return error code to user
			full_log << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			full_log  << (i-1) << "! = " << product << " but " << i << "! = " << temp << endl << endl;
			return -2;
		}
	}
    full_log.close();
	return product;
}

double factorial ( double x ) {
	// return  error codes are slightly different from the integer function -> to differentiate between the two functions
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    // error detection : factorial not defined for x less than 0
	if ( x < 0.0 ) return -1.1;
	// if x is 0 , return 0
	if ( x == 0.0) return 0;

	double product = 1.0;
	double temp;
	// generate an inf variable for checking overflow during iterations
	double inf = 2.0/0.0;
	// calculate factorial through successive multiplication
	for ( double i=1.0 ; i<=x ; i++ ) {
		temp = product*i;
		// if the new product has not overflowed to inf, proceed to next iteration
		if ( temp != inf ) product = temp;
		else {
			// else if inf has been generated, return error code to user
			full_log << endl << "---------- overflow occured at " << i << "th iteration ----------" << endl;
			full_log << (i-1) << "! = " << product << " but " << i << "! = " << temp << endl << endl;
			return -2.1;
		}
	}
    full_log.close();
	return product;
}

int fibonacci ( int sequence ) {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    // error detection : fibonacci not defined for negative number of terms
	if ( sequence <= 0 ) return -1;
	// initialize first two terms
	int sum = 1;
	int sum_prev = 1; 
	// calculate the successive terms through repeated addition
	for ( int i = 3 ; i <= sequence ; i++ ) {
		int temp = sum;
		sum += sum_prev;
		// check if the new sum is actually the sum of the previous two 
		// if reverse calculation failed, overflow has occured; return error code to user
		if ( ( (sum_prev > 0) && (temp > 0) && (sum < 0) ) || (sum-sum_prev != temp) ) {
			full_log << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			full_log << (i-1) << "th term = " << temp << " but " << i <<"th term = " << sum << endl << endl;
			return -2;
		}
		// else proceed to next iteration
		else sum_prev = temp;
	}
	return sum;
    full_log.close();
}


double fibonacci( double sequence ) {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    // error detection : fibonacci not defined for negative number of terms
	if ( sequence <= 0 ) return -1.1;
	// initialize first two terms
	double sum = 1;
	double sum_prev = 1;
	// generate inf variable to check for overflow
	double inf = 2.0/0.0;
	// calculate the successive terms through repeated addition
	for ( double i = 3 ; i <= sequence ; i++ ) {
		double temp = sum;
		sum += sum_prev;
		// if the new sum has reached infinity, then overflow has occured - return error code to user
		if (sum==inf) {
			full_log << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			full_log << (i-1) << "th term = " << temp << " but " << i <<"th term = " << sum << endl << endl;
			return -2.1;
		}
		// else proceed with iteration
		sum_prev = temp;
	}
    full_log.close();
	return sum;
}

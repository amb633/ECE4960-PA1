# include "overflow.hpp"

int factorial ( int x ) {
	// error detection : x cannot be less than 0
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	if ( x< 0 ) return -1;
	if ( x == 0 ) return 0;

	int product = 1;
	int temp;
	for ( int i = 1 ; i <=x ; i++ ) {
		temp = product*i;
		if ( temp/i == product )
			product = temp;
		else {
			full_log << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			full_log  << (i-1) << "! = " << product << " but " << i << "! = " << temp << endl << endl;
			return -2;
		}
	}
    full_log.close();
	return product;
}

double factorial ( double x ) {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	if ( x < 0.0 ) return -1.1;
	if ( x == 0.0) return 0;

	double product = 1.0;
	double temp;
	double inf = 2.0/0.0;
	for ( double i=1.0 ; i<=x ; i++ ) {
		temp = product*i;
		if ( temp != inf ) product = temp;
		else {
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
	if ( sequence <= 0 ) return -1;
	int sum = 1;
	int sum_prev = 1; 

	for ( int i = 3 ; i <= sequence ; i++ ) {
		int temp = sum;
		sum += sum_prev;
		if ( ( (sum_prev > 0) && (temp > 0) && (sum < 0) ) || (sum-sum_prev != temp) ) {
			full_log << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			full_log << (i-1) << "th term = " << temp << " but " << i <<"th term = " << sum << endl << endl;
			return -2;
		}
		else sum_prev = temp;
	}
	return sum;
    full_log.close();
}


double fibonacci( double sequence ) {
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
	if ( sequence <= 0 ) return -1.1;
	double sum = 1;
	double sum_prev = 1;
	double inf = 2.0/0.0;
	for ( double i = 3 ; i <= sequence ; i++ ) {
		double temp = sum;
		sum += sum_prev;
		sum_prev = temp;
		//cout << i << " : " << sum << endl;
		if (sum==inf) {
			full_log << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			full_log << (i-1) << "th term = " << temp << " but " << i <<"th term = " << sum << endl << endl;
			return -2.1;
		}
	}
    full_log.close();
	return sum;
}

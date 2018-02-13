# include "overflow.hpp"

int factorial ( int x ) {
	// error detection : x cannot be less than 0
	if ( x< 0 ) return -1;
	if ( x == 0 ) return 0;

	int product = 1;
	int temp;
	for ( int i = 1 ; i <=x ; i++ ) {
		temp = product*i;
		if ( temp/i == product )
			product = temp;
		else {
			cout << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			cout  << (i-1) << "! = " << product << " but " << i << "! = " << temp << endl << endl;
			return -2;
		}
	}
	return product;
}

double factorial ( double x ) {
	if ( x < 0.0 ) return -1;
	if ( x == 0.0) return 0;

	double product = 1.0;
	double temp;
	double inf = 2.0/0.0;
	for ( double i=1.0 ; i<=x ; i++ ) {
		temp = product*i;
		if ( temp != inf ) product = temp;
		else {
			cout << endl << "---------- overflow occured at " << i << "th iteration ----------" << endl;
			cout << (i-1) << "! = " << product << " but " << i << "! = " << temp << endl << endl;
			return -2.1;
		}
	}
	return product;
}

int fibonacci ( int sequence ) {
	if ( sequence <= 0 ) return -1;
	int sum = 1;
	int sum_prev = 1; 

	for ( int i = 3 ; i <= sequence ; i++ ) {
		int temp = sum;
		sum += sum_prev;
		if ( sum_prev > 0 && temp > 0 && sum < 0 || sum-sum_prev != temp ) {
			cout << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			cout << (i-1) << "th term = " << temp << " but " << i <<"th term = " << sum << endl << endl;
			return -2;
		}
		else sum_prev = temp;
	}
	return sum;
}


double fibonacci( double sequence ) {
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
			cout << endl << "--------- overflow occured at " << i <<"th iteration ----------" << endl;
			cout << (i-1) << "th term = " << temp << " but " << i <<"th term = " << sum << endl << endl;
			return -2.1;
		}
	}
	return sum;
}
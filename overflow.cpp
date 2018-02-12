# include "overflow.hpp"

int factorial ( int x ) {
	// error detection : x cannot be less than 1
	if (x <= 0) return -1;

	int product = 1;
	int product_prev;
	for ( int i = 1 ; i <= x ; i++ ) {
		product_prev = product;
		product *= i;
		//cout << i << " : " << product << endl;
		if ( product < product_prev ) {
			cout << endl << " ---------- overflow occured at " << i <<"th iteration ---------- " << endl;
			cout << i << " : " << product << endl << endl;
			return -2;
		}
	}
	return product;
}

double factorial ( double x ) {
	// error detection : x cannot be less than 1
	if ( x <= 0.0 ) return -1.1;

	double product = 1;
	for ( double i = 1 ; i <= x ; i++ ) {
		product *= i;
		//cout << i << " : " << product << endl;
		if ( product == INFINITY ) {
			cout << endl << " ---------- overflow occured at " << i <<"th iteration ---------- " << endl;
			cout << i << " : " << product << endl << endl;
			return -2.1;
		}
	}
	return product;
}

int fibonacci( int sequence ) {
	if ( sequence <= 0 ) return -1;
	int sum = 1;
	int sum_prev = 1;
	for ( int i = 3 ; i <= sequence ; i++ ) {
		int temp = sum;
		sum += sum_prev;
		sum_prev = temp;
		//cout << i << " : " << sum << endl;
		if (sum<sum_prev) {
			cout << endl << " ---------- overflow occured at " << i <<"th iteration ---------- " << endl;
			cout << i << " : " << sum << endl << endl;
			return -2;
		}
	}
	return sum;
}

double fibonacci( double sequence ) {
	if ( sequence <= 0 ) return -1.1;
	double sum = 1;
	double sum_prev = 1;
	for ( double i = 3 ; i <= sequence ; i++ ) {
		double temp = sum;
		sum += sum_prev;
		sum_prev = temp;
		//cout << i << " : " << sum << endl;
		if (sum==INFINITY) {
			cout << endl << " ---------- overflow occured at " << i <<"th iteration ---------- " << endl;
			cout << i << " : " << sum << endl << endl;
			return -2.1;
		}
	}
	return sum;
}
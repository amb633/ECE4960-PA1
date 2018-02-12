#include "functions.h"

int factorial ( int x ) {
	int product = 1;
	int product_prev;
	for ( int i = 1 ; i <= x ; i++ ){
		product_prev = product;
		product *= i;
		cout << i << " : " << product << endl;
		/*if ( product < product_prev ) {
			cout << " ---------- overflow occured at " << i << "th iteration ---------- " << endl;
			return product;
		}*/
	}
	return product;
}

double factorial ( double x ) {
	double product = 1;
	double product_prev;
	for ( double i = 1 ; i <= x ; i ++ ) {
		product_prev = product;
		product *= i;
		cout << i << " : " << product << endl;
	}
	return product;
}

int fibonacci( int sequence ){
	int sum = 1;
	int sum_prev = 1;
	int temp;
	for ( int i = 3 ; i <= sequence ; i++ ) {
		temp = sum;
		sum += sum_prev;
		sum_prev = temp;
		cout << i << " : " << sum << endl;
		if ( sum < sum_prev ) {
			cout << " ---------- overflow occured at " << i << "th iteration ---------- " << endl;
			return sum;
		}
	}

	return sum;
}

double fibonacci_d ( int sequence ) {
	double sum = 1.0;
	double sum_prev = 1.0;
	double temp;
	for ( int i = 3 ; i <= sequence ; i ++ ) {
		temp = sum;
		sum += sum_prev;
		sum_prev = temp;
		cout << i << " : " << sum << endl;
	}
	return sum;
}
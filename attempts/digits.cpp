#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

void countDigits( int& count_int , int& count_zeros , int& count_decimal , double num );
void getDigits( int* digits , double num , int count_int , int count_decimal , int count_zeros );
int exponent( int n );
int lastNumber ( double num );

int main(int argc, char const *argv[])
{
	int digits1[16];
	int digits2[16];
	int digits3[16];

	double n1 = 123456.7890123456;
	double n2 = 1.234567890123456*pow(1,20);
	double n3 = 1.234567890123456*pow(1,-20);

	int count_int , count_zeros , count_decimal;

	countDigits( count_int , count_zeros , count_decimal , n3 );
	getDigits( digits1 , n3 , count_int , count_decimal , count_zeros );

	for ( int i = 0 ; i < 16 ; i++ ){
		cout << digits1[i] << endl;
	}

	return 0;
}

void countDigits( int& count_int , int& count_zeros , int& count_decimal , double num ){
	// first count no. of digits to left of decimal place
	count_int = 0;
	if (num < 0) num *=-1;
	int num_int = (int)num;
	while( num_int != 0 ) {
		count_int++;
		num_int /= 10;
	}

	count_zeros = 0;
	count_decimal = 0;

	if ( count_int > 0 ) count_decimal = 16 - count_int;
	else {
		int temp = 0;
		while ( temp == 0 ){
			num*=10;
			temp = (int)num%10;
			count_zeros++;
		}
		count_zeros--;  // to get the number of zeros instead of the position of the starting digit
		count_decimal = 16;
	}
}

void getDigits( int* digits , double num , int count_int , int count_decimal , int count_zeros ){
	int d = 0;
	int num_int = (int)num;
	for ( int ii = 1 ; ii <= count_int ; ii++ ){
		int digit = num_int/exponent(count_int-ii);
		num_int -= digit*exponent(count_int-ii);
		digits[d] = digit;
		d++;
	}

	num *= exponent(count_zeros);
	num -= int(num);

	for ( int ii = 0 ; ii < count_decimal-1 ; ii++ ){
		num *=10;
		int digit = (int)num%10;
		digits[d] = digit;
		num -= digit;
		d++;
	}

	num *= 10;
	int last = lastNumber(num);
	digits[d] = last;

}

int exponent ( int n ){
	int e = 1;
	for ( int i = 0 ; i < n ; i++ ){
		e *=10;
	}
	return e;
}

int lastNumber( double num ) {
	int n = (int)(num*10); 
	int r = (n)%10;
	n = (int)num;
	if ( r>= 5 ) {
		return ((n%10)+1);
	}
	else return (n%10);
}
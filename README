ECE4960 - Programming Assignment 1 Arithmetic Exception Handling

Overview: Implementation of programs and functions to observe and detect arithmetic exceptions on C++. 

Usage: Download and run ./make.sh from the command line. Output log for the exception rules will be generated as "full_log_output.txt", and the quad precision log will be stored in " .txt"

Documentation and Usage:

factorial(n) : overloaded function that will return the result of the factorial operation (n! = n(n-1)(n-2)...(1) ). input argument can be int or double, depending on which version of the function user intends to call. Both versions will return a negative error value if an overflow is generated. 

Examples: (for int) int fac_int = factorial(5) ; (for double) double fac_dbl = factorial(5.0);

fibonacci(n) : overloaded function that will return the nth term of the standard fibonacci sequence ( 1 , 1 , 2 , 3 , 5 , 8 ...). Input argument can be int or double, depending on which version the use intends to call. Both functions will return a negative error value if an overflow is generated.

Examples: (for int) int fib_int = fibonacci(5) ; (for double) double fib_dbl = fibonacci(5.0);

overflow_test.cpp shows instances of test functions that can be used to test the functionality of factorial() and fibonacci().

int_div_0( int a ) : function that will divide input argument (integer) a by 0. Will cause program to crash.

inverse_func( x ) : returns the floating point (fp) value of 1.0/x

sine_func( x ) : returns the fp value of sin(x)

expon_func( c ) : returns the fp value of exp(x)

detect_INF ( x ) : returns true if input argument x is equal to the fp value of INF

detect_NINF( x ) : returns true if input argument x is equal to the fp value of NINF

float_pt_ops_INF_and_NINF_tests.cpp shows the test cases of these functions, and how they handle inf as an input argument.

sqrtNegative ( x ) : returns the fp value of the square root of the negative of |x| 

logNegative ( x ) : returns the fp value of the square root of the natural log of the negative of |x|

infLessInf() : returns the fp value of inf - inf

infDivideInf() : returns the fp value of inf/inf

addNan( x , y ) : returns fp value of x + y

multiplyNan( x , y ) : returns fp value of x*y

sineNan( x ) : returns fp value of sin(x)

powerNan( x , y ) : returns fp value of x^y

infAndNan() : return fp value of inf + nan

detectNAN( x ) : returns true is input argument is a NAN

signed_zero_log( z ) : returns the behaviour of the log of a signed zero variable

signed_zero_sine_inverse( z ) : returns the behaviour of sin(z)/z

signed_zero_sine_abs_inverse( z ) : returns the behaviour of sin(z)/|z|

subtract( x , y , d , u ) : stores d = ( x-y ); and sets u to true if underflow has occurred

divide( x , y , d , u ) : stores d = (x/y); and sets u to true if underflow has occurred

sine_fcn( x , d , u ) : stores d = (sin(x))/x ; and sets u to true if underflow has occurred

underflow_test.cpp shows the test cases of these functions.

The full log of all exception handling can be viewed at "full_log_output.txt", and a summary can be obtained in IEEE Compliance Report.txt

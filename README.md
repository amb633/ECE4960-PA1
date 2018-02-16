# ECE4960 - Programming Assignment 1 Arithmetic Exception Handling

***************************************************************************
## Part 1 - Observation of Exception Rules
***************************************************************************

**Overview:**

Implementation of programs and functions to observe and detect arithmetic exceptions on C++. 

**Usage:**

Download and run `./make.sh` from the command line. This will generate an executable called `program1`. Then, run `./program1` from the command line. Output log for the exception rules will be generated as "`full_log_output.txt`".

**Documentation:**
*Functions for Testing Overflows*
 - `factorial(n)` : overloaded function that will return the result of the factorial operation (`n! = n(n-1)(n-2)...(1)`). input argument can be int or double, depending on which version of the function user intends to call. Both versions will return a negative error value if an overflow is generated. 

Examples: 
```
int fac_int = factorial(5);
double fac_dbl = factorial(5.0);
```

- `fibonacci(n)` : overloaded function that will return the nth term of the standard fibonacci sequence ( `1 , 1 , 2 , 3 , 5 , 8 ...`). Input argument can be int or double, depending on which version the use intends to call. Both functions will return a negative error value if an overflow is generated.

Examples: 
```
int fib_int = fibonacci(5); 
double fib_dbl = fibonacci(5.0)
```

- `overflow_test.cpp` shows instances of test functions that can be used to test the functionality of `factorial()` and `fibonacci()`.

*Division by zero*

- `int_div_0( int a )` : function that will divide input argument a by 0. Will cause program to crash.

*Functions for Operations with INF and NINF*
- `inverse_func( x )` : returns the floating point (fp) value of `1.0/x`

- `expon_func( c )` : returns the fp value of `exp(x)`

-`detect_INF ( x )` : returns true if input argument x is equal to the fp value of `INF`

-`detect_NINF( x )` : returns true if input argument x is equal to the fp value of `NINF`

-`float_pt_ops_INF_and_NINF_tests.cpp` shows the test cases of these functions, and how they handle `inf` as an input argument.


*Functions for Operations with NAN*

-`sqrtNegative ( x )` : returns the fp value of the square root of the negative of `|x|` 

-`logNegative ( x )` : returns the fp value of the square root of the natural log of the negative of `|x|`

-`infLessInf()` : returns the fp value of `inf - inf`

-`infDivideInf()` : returns the fp value of `inf/inf`

-`addNan( x , y )` : returns fp value of `x + y`

-`multiplyNan( x , y )` : returns fp value of `x*y`

-`sineNan( x )` : returns fp value of `sin(x)`

-`powerNan( x , y )` : returns fp value of `x^y`

-`infAndNan()` : return fp value of `inf + nan`

-`detectNAN( x )` : returns true is input argument is a `NAN`

*Functions for Operations with Signed Zeros*

-`signed_zero_log( z )` : returns the behaviour of the `log` of a signed zero variable

-`signed_zero_sine_inverse( z )` : returns the behaviour of `sin(z)/z`

-`signed_zero_sine_abs_inverse( z )` : returns the behaviour of `sin(z)/|z|`

*Functions for Underflow Operations*

-`subtract( x , y , d , u )` : stores `d = ( x-y );` and sets `u` to `true` if underflow has occurred

-`divide( x , y , d , u )` : stores `d = (x/y);` and sets `u` to `true` if underflow has occurred

-`sine_fcn( x , d , u )` : stores `d = (sin(x))/x` ; and sets `u` to `true` if underflow has occurred

-`underflow_test.cpp` shows the test cases of these functions.

The full log of all exception handling can be viewed at "`full_log_output.txt`", and a summary can be obtained in `IEEE Compliance Report.txt`

***************************************************************************
## Part 2 -  Application of Floating-Point Precision ( #2 )
***************************************************************************

**Overview:**

Implementing quad-precision addition and subtraction of two double-precision floating numbers. This section of the assignment can be found in the "QuadPrecision" folder

**Usage:**

To run this part, run `./make.sh` which uses the `g++` compiler to generate the program executable called "`quadprecision`". Run `./quadprecision` and the results will be in the "`test_log_output.txt`"

**Documentation:**

The results show 4 test cases of adding and subtracting two double-precision floating numbers and returns the quad-precision floating number result as two double-precision floating point numbers that can then be summed to represent the quad-precision value. 

The two main functions for quad-precision implementation are:

`addition_precision( number a, number b)`: returns a result addition_result: this function takes two `number` variables and performs a addition and gives the `result` variable with two double-precision floating point number

 
`subtract_precision( number a, number b)`: returns a result subtract_result: this function takes two `number` variables and performs a subtraction and gives the `result` variable with two double-precision floating point number

The two main variable structures that are used are:

`number` -- composed of:
- the value of the double precision floating point number
- the integer part of the double precision floating point number
- the fraction part of the double precision floating point number
- the start position of double precision floating point number from the decimal point
- the end position of double precision floating point number from the decimal point

`result` -- composed of:
- most significant precision value of the result which is represented as a `number` structure
- least significant precision value of the result number which is represented as a `number` structure



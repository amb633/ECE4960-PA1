//
//
//Programming Assignment 1
//Collaboration by Ariana Bruno and Haritha Murali
//Due Wednesday 02/14/2018
//
//
//

#include "overflow.hpp"
#include "int_div_0.hpp"
#include "float_pt_ops_INF_and_NINF.hpp"
#include "signed_zero_behavior.hpp"
#include <limits>  //for the infinity();

using namespace std;

int main() {
    
    //**********************************************
    // Part 1: Integer overflows
    cout << endl;
    cout << boolalpha;
    
    cout << "integer factorial function working?  " << test_factorial_int() << endl;
    cout << "error test for integer factorial fcn " << test_factorial_int_error() << endl;
    cout << "overflow test for int factorial fcn  " << test_factorial_int_overflow() << endl;
    
    cout << "integer fibonacci function working?  " << test_fibonacci_int() << endl;
    cout << "error test for integer fibonacci fcn " << test_fibonacci_int_error() << endl;
    cout << "overflow test for int fibonacci fcn  " << test_fibonacci_int_overflow() << endl;
    
    
    cout << endl;
    
    //**********************************************
    // Part 2: Integer divided by 0
    // Running this portion to create compiler exception for int divided by 0
    /*int err = int_div_0(5);
    cout << err << endl;*/
    cout << "Integer divided by 0: This results in a compiler error" << endl;
    
    cout<<endl;
    
    //**********************************************
    // Part 3: Floating Point Overflows
    cout << "double  factorial function working? " << test_factorial_double() << endl;
    cout << "error test for double factorial fcn " << test_factorial_double_error() << endl;
    cout << "overflow test for double factorial  " << test_factorial_double_overflow() << endl;
    
    cout << "double fibonacci function working?  " << test_fibonacci_double() << endl;
    cout << "error test for double fibonacci fcn " << test_fibonacci_double_error() << endl;
    cout << "overflow test for double fibonacci  " << test_fibonacci_double_overflow() << endl;
    
    cout<<endl;
    
    //**********************************************
    // Part 4: Floating Point Operations of INF and NINF
    float INF = std::numeric_limits<float>::infinity();
    float NINF = -1*INF;
    
    cout<< "Trying the inverse, sine, and exponential function for INF first: " << endl;
    
    cout << "This is 1/INF: " << inverse_func(INF) << endl;
    cout << "This is sin(INF): " << sine_func(INF) << endl;
    cout << "This is e^INF: "  << expon_func(INF) << endl;
    
    cout<< "Trying the inverse, sine, and exponential function for NINF second: " << endl;
    
    cout << "This is 1/NINF: " << inverse_func(NINF) << endl;
    cout << "This is sin(NINF): " << sine_func(NINF) << endl;
    cout << "This is e^NINF: "  << expon_func(NINF) << endl;
    
    //**********************************************
    // Part 6: Signed Zero
    
    float pos_zero = +0.0;
    float neg_zero = -0.0;
    
    signed_zero_log(pos_zero);
    signed_zero_log(neg_zero);

    
    
	return 0;
}


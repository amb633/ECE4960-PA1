//
//
//Programming Assignment 1
//Collaboration by Ariana Bruno and Haritha Murali
//Due Wednesday 02/14/2018
//
//
//

#include <fstream>
#include "overflow.hpp"
#include "int_div_0.hpp"
#include "notanumber.hpp"
#include "float_pt_ops_INF_and_NINF.hpp"
#include "signed_zero_behavior.hpp"
#include "underflow.hpp"
#include <limits>  //for the infinity();

using namespace std;

int main() {
    
    ofstream full_log;
    full_log.open ("full_log_output.txt");
    //myfile << "Writing this to a file.\n";
    full_log << "\n\nProgram Assignment 1\n";
    full_log << "By Ariana Bruno and Haritha Murali\n";
    full_log << "netID: amb633 hm535\n";
    
    //**********************************************
    // Part 1: Integer overflows
    //cout << endl;
    full_log << "\n****************** Part 1: Integer Overflows ******************\n";
    full_log << boolalpha;
    
    full_log << "integer factorial function working?  " << test_factorial_int() << endl;
    full_log << "error test for integer factorial fcn " << test_factorial_int_error() << endl;
    full_log << "overflow test for int factorial fcn  " << test_factorial_int_overflow() << endl;
    
    full_log << "integer fibonacci function working?  " << test_fibonacci_int() << endl;
    full_log << "error test for integer fibonacci fcn " << test_fibonacci_int_error() << endl;
    full_log << "overflow test for int fibonacci fcn  " << test_fibonacci_int_overflow() << endl;
    
    
    full_log << endl;
    
    //**********************************************
    // Part 2: Integer divided by 0
    
    full_log << "\n****************** Part 2: Integer Divided By 0 ******************\n";
    
    // Running this portion to create compiler exception for int divided by 0
    /*int err = int_div_0(5);
    cout << err << endl;*/
    full_log << "Integer divided by 0: This results in a compiler error" << endl;
    
    full_log<<endl;
    
    //**********************************************
    // Part 3: Floating Point Overflows
    
    full_log << "\n****************** Part 3: Floating Point Overflows ******************\n";
    
    full_log << "double  factorial function working? " << test_factorial_double() << endl;
    full_log << "error test for double factorial fcn " << test_factorial_double_error() << endl;
    full_log << "overflow test for double factorial  " << test_factorial_double_overflow() << endl;
    
    full_log << "double fibonacci function working?  " << test_fibonacci_double() << endl;
    full_log << "error test for double fibonacci fcn " << test_fibonacci_double_error() << endl;
    full_log << "overflow test for double fibonacci  " << test_fibonacci_double_overflow() << endl;
    
    full_log<<endl;
    
    //**********************************************
    // Part 4: Floating Point Operations of INF and NINF
    full_log << "\n****************** Part 4: Floating Point Operations of INF and NINF ******************\n";
    
    full_log << "Trying the inverse, sine, and exponential function for INF first: " << endl;
    
    full_log.close();
    test_INF_functions();
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    
    full_log << "Trying the inverse, sine, and exponential function for NINF second: " << endl;
    
    full_log.close();
    test_NINF_functions();
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    full_log << "Trying the propagation of INF and NINF second: " << endl;
    
    full_log.close();
    test_INF_NINF_propogation();
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    full_log << "Trying the detection of INF and NINF: " << endl;
    full_log << "detection of INF [EXPECT true]: dectect_INF(exp(pow(10.0,20.0)))= " <<
    detect_INF(exp(pow(10.0,20.0))) << endl;
    
    full_log << "detection of INF [EXPECT false]: dectect_INF(log(0.0))= " <<
    detect_INF(log(0.0)) << endl;
    
    full_log << "detection of NINF [EXPECT true]: dectect_NINF(log(0.0))= " <<
    detect_NINF(log(0.0)) << endl;
    
    full_log << "detection of NINF [EXPECT false]: dectect_NINF(exp(pow(10.0,20.0)))= " <<
    detect_NINF(exp(pow(10.0,20.0))) << endl;
    full_log << endl;
    
    
    //**********************************************
    // Part 5: Not a Number
    
    full_log << "\n****************** Part 5: Not a Number ******************\n";

    full_log << "sqrt of a negative number returns a " << sqrtNegative( -10 ) << endl;
    full_log << "log of a negative number returns a  " << logNegative ( -10 ) << endl;
    full_log << "infinty minus infinty returns a " << infLessInf() << endl;
    full_log << "infinty divided by infinty returns a " << infDivideInf() << endl;

    full_log << "detection of NAN: detectNan(-1) gives a " << detectNan(-1) << endl;
    full_log << "detection of NAN: detectNan(2) gives a " << detectNan(2) << endl;
    full_log << "detection of NAN: detectNan(10) gives a " << detectNan(10) << endl;
    full_log << "detection of NAN: detectNan(inf) gives a " << detectNan(10.0/0.0) << endl;
    full_log << "detection of NAN: detectNan( sqrt(-10)) gives a " << detectNan(sqrtNegative(-10)) << endl;
    full_log << "detection of NAN: detectNan( log(-10) ) gives a " << detectNan(logNegative(-10)) << endl;

    full_log << "propagation of NAN: adding nan to any number returns a " << addNan( 2 , NAN ) << endl;
    full_log << "propagation of NAN: multiplying nan to a number returns a " << multiplyNan( 10 , NAN ) << endl;
    full_log << "propagation of NAN: sine of nan returns a " << sineNan(NAN) << endl;
    full_log << "propagation of NAN: power of nan returns a " << powerNan(NAN,2) << endl;

    full_log << "interaction with other INF: inf + nan returns " << infAndNan() << endl;
    full_log << endl;

    //**********************************************
    // Part 6: Signed Zero
    full_log << "\n****************** Part 6: Signed Zero ******************\n";
    float pos_zero = +0.0;
    float neg_zero = -0.0;
    
    full_log<< "Trying the log(x) as x->+0: " << endl;
    full_log.close();
    signed_zero_log(pos_zero);
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    full_log<< "Trying the log(x) as x->-0: " << endl;
    full_log.close();
    signed_zero_log(neg_zero);
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    full_log<< "Trying the sin(x)/x as x->+0: " << endl;
    full_log.close();
    signed_zero_sine_inverse(pos_zero);
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    full_log<< "Trying the sin(x)/x as x->-0: " << endl;
    full_log.close();
    signed_zero_sine_inverse(neg_zero);
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    full_log<< "Trying the sin(x)/|x| as x->-0: " << endl;
    full_log.close();
    signed_zero_sine_abs_inverse(neg_zero);
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl;
    
    //**********************************************
    // Part 7: Floating Point Gradual Underflow
    
    full_log << "\n****************** Part 7: Floating Point Gradual Underflow ******************\n";
    
    full_log << endl << " ---------- Underflow with Subtraction ---------- " << endl;
    
    full_log.close();
    underflow_via_subtraction();
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    
    full_log << endl << " ---------- Underflow with Division ---------- " << endl;
    
    full_log.close();
    underflow_via_division();
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    
    full_log << endl << " ---------- Underflow with Sine ---------- " << endl;
    
    full_log.close();
    underflow_via_sine();
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);

    full_log << endl;
    
    full_log.close();
    
	return 0;
}


//
//  main.cpp
//  QuadPrecision
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include "precision_functions.hpp"


int main(int argc, const char * argv[]) {
    
    ofstream full_log;
    full_log.open ("test_log_output.txt");
    
    full_log << "************* Applications of foating point precision #2 *************" << endl << endl;
    
    full_log << "------------- Tests of Addition and Subtraction -------------" << endl << endl;
    full_log.precision(16);
    full_log << boolalpha;
    
//    This is testing overlap of one digit
    long double a = 1234567890.123456;
    long double b = 0.000007890123456789012;
    long double a_b_add_expected1 = 1234567890.123463;
    long double a_b_add_expected2 = 8.90123456789012e-07;
    bool a_b_correctness_add = test_addition( a, b, a_b_add_expected1, a_b_add_expected2);
    full_log<< a << " + " << b << " = " << a_b_add_expected1 << " & " << a_b_add_expected2 << ": " << a_b_correctness_add << endl;
    long double a_b_sub_expected1 = 1234567890.123448;
    long double a_b_sub_expected2 = 1.09876543210988e-07;
    bool a_b_correctness_sub = test_subtraction( a, b, a_b_sub_expected1, a_b_sub_expected2);
    full_log<< a << " - " << b << " = " << a_b_sub_expected1 << " & " << a_b_sub_expected2 << ": " << a_b_correctness_sub << endl;
    full_log<< endl;

//    This is testing overlap of 6 digits
    long double c = 1000000001.000001;
    long double d = 0.100000100100001;
    long double c_d_add_expected1 = 1000000001.100001;
    long double c_d_add_expected2 = 0.000000100100001;
    bool c_d_correctness_add = test_addition( c, d, c_d_add_expected1, c_d_add_expected2);
    full_log<< c << " + " << d << " = " << c_d_add_expected1 << " & " << c_d_add_expected2 << ": " << c_d_correctness_add << endl;
    long double c_d_sub_expected1 = 1000000000.900000;
    long double c_d_sub_expected2 = 0.000000899899999;
    bool c_d_correctness_sub = test_subtraction( c, d, c_d_sub_expected1, c_d_sub_expected2);
    full_log<< c << " - " << d << " = " << c_d_sub_expected1 << " & " << c_d_sub_expected2 << ": " << c_d_correctness_sub << endl;
    full_log << endl;
    
//    This is testing overlap of 16 digits as integers
    long double e = 1234567890123456.0;
    long double f = 7890123456789012.0;
    long double e_f_add_expected1 = 9124691346912468.0;
    long double e_f_add_expected2 = 0.0;
    bool e_f_correctness_add = test_addition( e, f, e_f_add_expected1, e_f_add_expected2);
    full_log<< e << " + " << f << " = " << e_f_add_expected1 << " & " << e_f_add_expected2 << ": " << e_f_correctness_add << endl;
    long double e_f_sub_expected1 = -6655555566665556;
    long double e_f_sub_expected2 = 0.0;
    bool e_f_correctness_sub = test_subtraction( e, f, e_f_sub_expected1, e_f_sub_expected2);
    full_log<< e << " - " << f << " = " << e_f_sub_expected1 << " & " << e_f_sub_expected2 << ": " << e_f_correctness_sub << endl;
    full_log<<endl;
    
//    This is testing overlap of 16 digits as fractions
    long double g = 0.1234567890123456;
    long double h = 0.7890123456789012;
    long double g_h_add_expected1 = 0.9124691346912468;
    long double g_h_add_expected2 = 0.0;
    bool g_h_correctness_add = test_addition( g, h, g_h_add_expected1, g_h_add_expected2);
    full_log<< g << " + " << h << " = " << g_h_add_expected1 << " & " << g_h_add_expected2 << ": " << g_h_correctness_add << endl;
    long double g_h_sub_expected1 =-0.6655555566665556;
    long double g_h_sub_expected2 = 0.0;
    bool g_h_correctness_sub = test_subtraction( g, h, g_h_sub_expected1, g_h_sub_expected2);
    full_log<< g << " - " << h << " = " << g_h_sub_expected1 << " & " << g_h_sub_expected2 << ": " << g_h_correctness_sub << endl;
    full_log << endl;
    
    
    return 0;
}

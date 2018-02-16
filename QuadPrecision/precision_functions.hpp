//
//  precision_handling.hpp
//  QuadPrecision
//
//  Created by Ariana Bruno on 2/15/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef precision_functions_hpp
#define precision_functions_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

typedef struct number{
    long double value;
    long double integer;
    long double fraction;
    int start;
    int end;
} number;

typedef struct result{
    number most_significant;
    number least_significant;
} result;

int pos_start_dist_from_decimal( long double num );
int neg_start_dist_from_decimal( long double num );
int start_dist_from_decimal( number num );
int end_dist_from_decimal( long double start_pos );
number construct_number( long double value );
int check_overlap(number num1, number num2);
long double most_significant_precision(long double num1, long double num2);
long double split_larger( long double num, int end );
long double carry_over( int precision );
long double correct_precision( int precision, number num );
result addition_precision( number num1, number num2 );
result subtraction_precision(number num1, number num2);

/******** Test Functions ***********/
bool test_addition(long double a, long double b, long double expected_result1, long double expected_result2);
bool test_subtraction(long double a, long double b, long double expected_result1, long double expected_result2);
bool comparison_error( long double expected_value, long double result );
long double calculate_error( long double expected_value, long double result );

#endif /* precision_functions_hpp */

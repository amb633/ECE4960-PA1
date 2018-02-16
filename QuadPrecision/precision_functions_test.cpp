//
//  precision_functions_test.cpp
//  QuadPrecision
//
//  Created by Ariana Bruno on 2/15/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "precision_functions.hpp"

bool test_addition(long double a, long double b, long double expected_result1, long double expected_result2){
    number num1 = construct_number(a);
    number num2 = construct_number(b);
    
    result add = addition_precision(num1, num2);
    
    if (comparison_error( expected_result1, add.most_significant.value) && comparison_error( expected_result2, add.least_significant.value)){
        return true;
    } else {
        return false;
    }
}

bool test_subtraction(long double a, long double b, long double expected_result1, long double expected_result2){
    number num1 = construct_number(a);
    number num2 = construct_number(b);
    
    result subtract = subtraction_precision(num1, num2);
    
    if (comparison_error(expected_result1, subtract.most_significant.value) && comparison_error( expected_result2, subtract.least_significant.value)){
        return true;
    } else {
        return false;
    }
}

bool comparison_error( long double expected_value, long double result ){
    if ((expected_value == result) || (calculate_error( expected_value, result ) < 1e-16 )){
        return true;
    } else {
        return false;
    }
}

long double calculate_error( long double expected_value, long double result ){
    return abs( expected_value - result )/expected_value;
}

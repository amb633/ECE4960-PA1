//
//  precision_functions_test.cpp
//  QuadPrecision
//
//

#include "precision_functions.hpp"

//Testing the addition of two double-precision values and returns "true" if the results match the
//given expected results, and returns "false" otherwise
bool test_addition(long double a, long double b, long double expected_result1, long double expected_result2){
    
    //constructs the inputs to number structure
    number num1 = construct_number(a);
    number num2 = construct_number(b);
    
    //calculates the addition result
    result add = addition_precision(num1, num2);
    
    //compares the addition result to expected values
    if (comparison_error( expected_result1, add.most_significant.value) && comparison_error( expected_result2, add.least_significant.value)){
        return true;
    } else {
        return false;
    }
}

//Testing the subtraction of two double-precision values and returns "true" if the results match the
//given expected results, and returns "false" otherwise
bool test_subtraction(long double a, long double b, long double expected_result1, long double expected_result2){
    
    //constructs the inputs to number structure
    number num1 = construct_number(a);
    number num2 = construct_number(b);
    
    //calculates the addition result
    result subtract = subtraction_precision(num1, num2);
    
    //compares the addition result to expected values
    if (comparison_error(expected_result1, subtract.most_significant.value) && comparison_error( expected_result2, subtract.least_significant.value)){
        return true;
    } else {
        return false;
    }
}

//Returns true or false is the expected value is equal to the result within 1e-16 precision error
bool comparison_error( long double expected_value, long double result ){
    if ((expected_value == result) || (calculate_error( expected_value, result ) < 1e-16 )){
        return true;
    } else {
        return false;
    }
}

//Calculates the precision error between the expected and the result values
long double calculate_error( long double expected_value, long double result ){
    return abs( expected_value - result )/expected_value;
}

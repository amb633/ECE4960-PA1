//
//  precision_handling.cpp
//  QuadPrecision
//

#include "precision_functions.hpp"

//Calculates the position of the first value from the decimal place (to the left)
int pos_start_dist_from_decimal( long double num ){
    int count = 0;
    long double int_size = 1;
    while (abs(floor(num)) > int_size){
        count++;
        int_size *=10;
    }
    return count;
}

//Calculates the position of the first value from the decimal place (to the right)
int neg_start_dist_from_decimal( long double num ){
    int count = 0;
    while (abs(floor(num)) <= 0.0){
        count--;
        num *=10;
    }
    return count+1;
}

//Calculates the distance of the first value from the decimal
//if the start was negative (to the right of the decimal) then the positive start is always zero
//if the start was positive (to the left of the decimal) then the negative start is always zero
int start_dist_from_decimal( number num ){
    int pos_start = pos_start_dist_from_decimal(num.integer);
    int neg_start = (pos_start == 0) ? neg_start_dist_from_decimal(num.fraction) : 0;
    return pos_start + neg_start;
}

//Calculates the position of the last digit from the decimal
int end_dist_from_decimal( long double start_pos ){
    return (start_pos)-16;
}

//Construsts the number variable for a given double-precision floating point value
number construct_number( long double value ){
    number num;
    num.value = value;
    num.fraction = modf(num.value, &num.integer);
    num.start = start_dist_from_decimal(num);
    num.end = end_dist_from_decimal(num.start);
    return num;
}

//Compares the two numbers to see how many digits overlap/interact in the algebraic operations
int check_overlap(number num1, number num2){
    int end, start;
    end =  (abs(num1.value) > abs(num2.value)) ? num1.end : num2.end;
    start = (abs(num1.value) > abs(num2.value)) ? num2.start : num1.start;
    
    if ( start > end){
        return start - end;
    }else{
        return -1;
    }
}

//Finds which number has the most significant digits
long double most_significant_precision(long double num1, long double num2){
    if( abs(num1) >= abs(num2) ){
        return num1;
    } else {
        return num2;
    }
}

//For splitting the number with the least significant digits
//and returning the part that overlaps with the number with the most significant digits
long double split_larger( long double num, int end ){
    for( int i = 0; i< abs(end) ; i++ ){
        num *=10;
    }
    num = floor(num);
    for( int i = 0; i< abs(end) ; i++ ){
        num /=10;
    }
    return num;
}

//To manage the arithmetic carry over from the most significant digits
//that occurs from doing subtraction of the least significant digits
long double carry_over( int precision ){
    long double value = 1.0;
    for(int i=0; i<abs(precision); i++){
        value = (precision > 0) ? value*10 : value/10;
    }
    return value;
}

//Checks that the result of the least significant digits are of
//the correct precision in the case where overlap occurs.
//When there is overlap between the two input numbers, we loose
//precision by the number of digits that are overlapping
long double correct_precision( int precision, number num ){
    long double value = num.value;
    for( int i = 0; i< abs(num.start) + precision; i++ ){
        if(num.start < 0){
            value *=10;
        } else{
            value /=10;
        }
    }
    //this truncates the error in precision
    value = floor(value);
    for ( int j = 0; j<precision + abs(num.start); j++ ){
        if(num.start < 0){
            value /=10;
        } else{
            value *=10;
        }
    }
    return value;
}



//Takes two double-precision floating point numbers that have been
//constructed as "number" structures and returns the addition of these
//two values as a "result" structure that contains two values: most_significant
//and least_significant double-precision floating point numbers
result addition_precision( number num1, number num2 ){
    
    //declaring variables for results
    result addition_result;
    number result_most_sig, result_least_sig;
    
    //Finds how many digits are overlaping between two numbers
    int overlap_amount = check_overlap(num1, num2);
    
    //If there is an overlap and it is not a complete overlap
    if( (overlap_amount > 0) && (overlap_amount < 16)){
        
        //Find the input value with most significant digits
        long double most_significant = most_significant_precision(num1.value, num2.value);
        
        if(most_significant == num1.value){
            //split the input with least significant digits into two, one that overlap with the
            //input with the most signficant digits and the digits that do not overlap
            number num2_split_large = construct_number(split_larger( num2.value, num1.end ));
            number num2_split_small = construct_number(num2.value - num2_split_large.value);
            num2_split_small.value = correct_precision(16-overlap_amount, num2_split_small);
            
            //Add the most signficant digits of the two inputs
            result_most_sig.value = num1.value + num2_split_large.value;
            result_least_sig.value = num2_split_small.value;
        }else{
            //split the input with least significant digits into two, one that overlap with the
            //input with the most signficant digits and the digits that do not overlap
            number num1_split_large = construct_number(split_larger( num1.value, num2.end ));
            number num1_split_small = construct_number(num1.value - num1_split_large.value);
            num1_split_small.value = correct_precision(16-overlap_amount, num1_split_small);
            
            //Add the most signficant digits of the two inputs
            result_most_sig.value = num2.value + num1_split_large.value;
            result_least_sig.value = num1_split_small.value ;
        }
        
    }else if (overlap_amount == 16){
        //Case where there is a direct overlap between the two inputs, the digits will just add as normal
        result_most_sig.value = num1.value + num2.value;
        result_least_sig.value = 0.0;
        
    } else {
        //Case where there is no overlap between the two inputs, the digits thus no addition needs to
        //occur with the digits
        result_most_sig.value = most_significant_precision( num1.value, num2.value );
        result_least_sig.value = ( result_most_sig.value == num1.value ) ? num1.value : num2.value;
    }
    
    //return the addition_result which is comprised of two values: the addition of the most signficant
    //digits and the addition of the least signficant digits
    addition_result.most_significant = result_most_sig;
    addition_result.least_significant = result_least_sig;
    return addition_result;
}



//Takes two double-precision floating point numbers that have been
//constructed as "number" structures and returns the subtraction of these
//two values as a "result" structure that contains two values: most_significant
//and least_significant double-precision floating point numbers
result subtraction_precision(number num1, number num2){
    //declaring variables for results
    result subtraction_result;
    number result_most_sig, result_least_sig;
    
    //Finds how many digits are overlaping between two numbers
    int overlap_amount = check_overlap(num1, num2);
    
    //If there is an overlap and it is not a complete overlap
    if( (overlap_amount >= 0) && (overlap_amount < 16)){
        
        //Find the input value with most significant digits
        long double most_significant = most_significant_precision(num1.value, num2.value);
        
        if(most_significant == num1.value){
            
            //split the input with least significant digits into two, one that overlap with the
            //input with the most signficant digits and the digits that do not overlap
            number num2_split_large = construct_number(split_larger(num2.value, num1.end));
            number num2_split_small = construct_number(num2.value - num2_split_large.value);
            num2_split_small.value = correct_precision(16-overlap_amount, num2_split_small);
            
            //Calculate the carry over value that needs to be included in the least significant digit subtraction
            long double carry_over_value = carry_over(num1.end);
            
            //Perform the subtraction on the most and least signficant digits
            result_most_sig = construct_number(num1.value - num2_split_large.value - carry_over_value);
            result_least_sig = construct_number(carry_over_value - num2_split_small.value);
            
        }else{
            //split the input with least significant digits into two, one that overlap with the
            //input with the most signficant digits and the digits that do not overlap
            number num1_split_large = construct_number(split_larger(num1.value, num2.end));
            number num1_split_small = construct_number(num1.value - num1_split_large.value);
            num1_split_small.value = correct_precision(16-overlap_amount, num1_split_small);
            
            //Calculate the carry over value that needs to be included in the least significant digit subtraction
            long double carry_over_value = carry_over(num2.end);
            
            //Perform the subtraction on the most and least signficant digits
            result_most_sig = construct_number(-1*(num2.value - num1_split_large.value - carry_over_value));
            result_least_sig = construct_number(-1*(carry_over_value + num1_split_small.value));
        }
    } else if (overlap_amount == 16) {
        //Case where there is a direct overlap between the two inputs, the digits will just subtract as normal
        result_most_sig.value = num1.value - num2.value;
        result_least_sig.value = 0.0;
    }
    
    //return the subtraction_result which is comprised of two values: the subtraction of the most signficant
    //digits and the subtraction of the least signficant digits
    subtraction_result.most_significant = result_most_sig;
    subtraction_result.least_significant = result_least_sig;
    return subtraction_result;
}

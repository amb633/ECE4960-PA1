//
//  precision_handling.cpp
//  QuadPrecision
//
//  Created by Ariana Bruno on 2/15/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "precision_functions.hpp"


int pos_start_dist_from_decimal( long double num ){
    int count = 0;
    long double int_size = 1;
    while (abs(floor(num)) > int_size){
        count++;
        int_size *=10;
        //        cout << "NUM: " << int_size << " and COUNT: " << count << endl;
    }
    return count;
}

int neg_start_dist_from_decimal( long double num ){
    int count = 0;
    while (abs(floor(num)) <= 0.0){
        count--;
        num *=10;
        //        cout << "NUM: " << floor(num) << " and COUNT: " << count << endl;
    }
    return count+1;
}

int start_dist_from_decimal( number num ){
    int pos_start = pos_start_dist_from_decimal(num.integer);
    int neg_start = (pos_start == 0) ? neg_start_dist_from_decimal(num.fraction) : 0;
    return pos_start + neg_start;
}

int end_dist_from_decimal( long double start_pos ){
    return (start_pos)-16;
}

number construct_number( long double value ){
    number num;
    num.value = value;
    num.fraction = modf(num.value, &num.integer);
    num.start = start_dist_from_decimal(num);
    num.end = end_dist_from_decimal(num.start);
    return num;
}

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

long double most_significant_precision(long double num1, long double num2){
    if( abs(num1) >= abs(num2) ){
        return num1;
    } else {
        return num2;
    }
}

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

long double carry_over( int precision ){
    long double value = 1.0;
    for(int i=0; i<abs(precision); i++){
        value = (precision > 0) ? value*10 : value/10;
    }
    return value;
}

long double correct_precision( int precision, number num ){
    long double value = num.value;
    for( int i = 0; i< abs(num.start) + precision; i++ ){
        if(num.start < 0){
            value *=10;
        } else{
            value /=10;
        }
    }
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

result addition_precision( number num1, number num2 ){
    result addition_result;
    number result_most_sig, result_least_sig;
    
    int overlap_amount = check_overlap(num1, num2);
//    cout << "These values are overlapping by: " << overlap_amount << " digits" << endl;
    
    if( (overlap_amount > 0) && (overlap_amount < 16)){
        long double most_significant = most_significant_precision(num1.value, num2.value);
        if(most_significant == num1.value){
            number num2_split_large = construct_number(split_larger( num2.value, num1.end ));
            number num2_split_small = construct_number(num2.value - num2_split_large.value);
            num2_split_small.value = correct_precision(16-overlap_amount, num2_split_small);
//            cout << "This is the num split value: " << num2_split_large.value << endl;
            
            result_most_sig.value = num1.value + num2_split_large.value;
            result_least_sig.value = num2_split_small.value;
        }else{
            number num1_split_large = construct_number(split_larger( num1.value, num2.end ));
            number num1_split_small = construct_number(num1.value - num1_split_large.value);
            num1_split_small.value = correct_precision(16-overlap_amount, num1_split_small);
//            cout << "This is the num split value: " << num1_split_large.value << endl;
            
            result_most_sig.value = num2.value + num1_split_large.value;
            result_least_sig.value = num1_split_small.value ;
        }
        
    }else if (overlap_amount == 16){
        result_most_sig.value = num1.value + num2.value;
        result_least_sig.value = 0.0;
        
    } else {
        result_most_sig.value = most_significant_precision( num1.value, num2.value );
        result_least_sig.value = ( result_most_sig.value == num1.value ) ? num1.value : num2.value;
    }
    
    addition_result.most_significant = result_most_sig;
    addition_result.least_significant = result_least_sig;
    return addition_result;
}


result subtraction_precision(number num1, number num2){
    result subtraction_result;
    number result_most_sig, result_least_sig;
    
    int overlap_amount = check_overlap(num1, num2);
//    cout << "These values are overlapping by: " << overlap_amount << " digits" << endl;
    
    if( (overlap_amount >= 0) && (overlap_amount < 16)){
        long double most_significant = most_significant_precision(num1.value, num2.value);
        if(most_significant == num1.value){
            
            number num2_split_large = construct_number(split_larger(num2.value, num1.end));
            number num2_split_small = construct_number(num2.value - num2_split_large.value);
            num2_split_small.value = correct_precision(16-overlap_amount, num2_split_small);
    //        cout << "This is the num split value: " << num2_split_large.value << endl;
            
            long double carry_over_value = carry_over(num1.end);
    //        cout << "This is the carry-over  value: " << carry_over_value << endl;
            
            result_most_sig = construct_number(num1.value - num2_split_large.value - carry_over_value);
            result_least_sig = construct_number(carry_over_value - num2_split_small.value);
            
        }else{
            
            number num1_split_large = construct_number(split_larger(num1.value, num2.end));
            number num1_split_small = construct_number(num1.value - num1_split_large.value);
            num1_split_small.value = correct_precision(16-overlap_amount, num1_split_small);
    //        cout << "This is the num split value: " << num1_split_large.value << endl;
            
            long double carry_over_value = carry_over(num2.end);
    //        cout << "This is the carry-over  value: " << carry_over_value << endl;
            
            result_most_sig = construct_number(-1*(num2.value - num1_split_large.value - carry_over_value));
            result_least_sig = construct_number(-1*(carry_over_value + num1_split_small.value));
        }
    } else if (overlap_amount == 16) {
        result_most_sig.value = num1.value - num2.value;
        result_least_sig.value = 0.0;
        
    }
    subtraction_result.most_significant = result_most_sig;
    subtraction_result.least_significant = result_least_sig;
    
    return subtraction_result;
}

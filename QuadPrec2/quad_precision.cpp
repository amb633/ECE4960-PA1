//
//  main.cpp
//  QuadPrecision
//
//  Created by Ariana Bruno on 2/14/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int pos_start_dist_from_decimal( double num ){
    int count = 0;
    double int_size = 1;
    while (abs(floor(num)) > int_size){
        count++;
        int_size *=10;
//        cout << "NUM: " << int_size << " and COUNT: " << count << endl;
    }
    return count;
}

int neg_start_dist_from_decimal( double num ){
    int count = 0;
    while (abs(floor(num)) <= 0.0){
        count--;
        num *=10;
//        cout << "NUM: " << floor(num) << " and COUNT: " << count << endl;
    }
    return count+1;
}

int end_dist_from_decimal( double start_pos ){
    return (start_pos)-16;
}

bool check_overlap(int start1, int end1, int start2, int end2){
    
    if ((start2 > end1) || (start1 > end2)){
        return true;
    } else {
        return false;
    }
}

long double most_significant_precision(long double num1, long double num2){
    if( abs(num1) >= abs(num2) ){
        return num1;
    } else {
        return num2;
    }
}

double split_larger( long double num, int end ){
    for( int i = 0; i< abs(end) ; i++ ){
        num *=10;
    }
    num = floor(num);
    for( int i = 0; i< abs(end) ; i++ ){
        num /=10;
    }
    return num;
}

void addition_precision( long double num1, int start1, int end1, long double num2, int start2, int end2 ){
    bool overlap = check_overlap(start1, end1, start2, end2);
    double result_most_sig, result_least_sig;
    if(overlap){
        double most_significant = most_significant_precision(num1, num2);
        if(most_significant == num1){
            double num2_split = split_larger(num2, end1);
            cout << "This is the num split value: " << num2_split << endl;
            result_most_sig = num1 + num2_split;
            result_least_sig = num2 - num2_split;
        }else{
            double num1_split = split_larger(num1, end2);
            cout << "This is the num split value: " << num1_split << endl;
            result_most_sig = num2 + num1_split;
            result_least_sig = num1 - num1_split;
        }
        
    }else{
        result_most_sig = most_significant_precision(num1, num2);
        result_least_sig = (result_most_sig==num1) ? num1 : num2;
    }
    cout << num1 << " + " << num2 << " = " << result_most_sig << " & " << result_least_sig << endl;
}

void subtraction_precision( long double num1, int start1, int end1, long double num2, int start2, int end2 ){
    bool overlap = check_overlap(start1, end1, start2, end2);
    double result_most_sig, result_least_sig;
    if(overlap){
        double most_significant = most_significant_precision(num1, num2);
        if(most_significant == num1){
            double num2_split = split_larger(num2, end1);
            cout << "This is the num split value: " << num2_split << endl;
            result_most_sig = num1 - num2_split;
            result_least_sig = (num2 - num2_split);
        }else{
            double num1_split = split_larger(num1, end2);
            cout << "This is the num split value: " << num1_split << endl;
            result_most_sig = num2 - num1_split;
            result_least_sig = 0.0 - (num1 - num1_split);
        }
        
    }else{
        result_most_sig = most_significant_precision(num1, num2);
        result_least_sig = (result_most_sig==num1) ? num1 : num2;
    }
    cout << num1 << " - " << num2 << " = " << result_most_sig << " & " << result_least_sig << endl;
}

int main(int argc, const char * argv[]) {
    
    cout.precision(16);
    
    long double a = 12345678901234567890123456789012.0;
    long double b = 1234567890.123456;
    long double d = 1000000001.000001;
    long double y = 0.1000001001000001;
    long double c = 0.000007890123456789012;
    long double x = 0.9999999999999999;
    
    
    double fraction1, integers1, fraction2, integers2;
    
    fraction1 = modf(b, &integers1);
    fraction2 = modf(c, &integers2);
    cout << boolalpha;
    
//    cout << "This is b: " << b << endl;
//    cout << "This is int(b): " << round(b) << endl;
//    cout << "This is b-int(b): " <<(b-(round(b))) << endl;
//    cout << "This is c: " << c << endl;
//    cout << "This is fraction: " << fraction << endl;
//    cout << "This is integers: " << integers << endl;
//    cout << "This is fraction2: " << fraction2 << endl;
//    cout << "This is integers2: " << integers2 << endl << endl;
//    cout << "This is b - integers: " << b- fraction << endl << endl;
    
//    cout << "This is x:   " << x << endl;
//    cout << "This is y:   " << y << endl;
//    cout << "This is x+y: " << x+y << endl;
//    cout << "This is b+c: " << b+c << endl;
    //cout << "This is b+d: " << b+d << endl;
    
    
    int pos_start1 = pos_start_dist_from_decimal(integers1);
    int pos_start2 = pos_start_dist_from_decimal(integers2);
    
    cout << "This is the pos dist from decimal for num1 and num2: " << pos_start1 << " and " << pos_start2 << endl;
    
    int neg_start1 = neg_start_dist_from_decimal(fraction1);
    int neg_start2 = neg_start_dist_from_decimal(fraction2);
    
    
    cout << "This is the neg dist from decimal for num1 and num2: " << neg_start1 << " and " << neg_start2 << endl;
    
    int start1 = pos_start1 + neg_start1;
    int start2 = pos_start2 + neg_start2;
    
    int end1 = end_dist_from_decimal(start1);
    int end2 = end_dist_from_decimal(start2);
    
    cout << "This is the end dist from decimal for num1 and num2: " << end1 << " and " << end2 << endl;
    
//    cout << "Overlap? " << check_overlap(start1, end1, start2, end2) << endl;
//    cout << "Larger Value? " << most_significant_precision(b,c) << endl;
//
//    cout << "This is split of smaller number for lager overlap: " << split_larger(c, end1) << endl;
//    cout << "Larger number + smaller number overlap: " << b + split_larger(c, end1) << " & " << c-split_larger(c, end1) << endl;
    
    addition_precision(b, start1, end1, c, start2, end2);
    //subtraction_precision(b, start1, end1, c, start2, end2);
    
    
    return 0;
}

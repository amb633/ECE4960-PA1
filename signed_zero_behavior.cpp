//
//  signed_zero_behavior.cpp
//  Program1
//
//  Created by Ariana Bruno on 2/12/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "signed_zero_behavior.hpp"

// Observe logarithmic behaviour as x tends to +/-0
void signed_zero_log( float signed_zero ){
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl << "------------ " << signed_zero << " behavior for log(x) =  ------------" << endl;
    // check if the argument is signed
    float sign = signbit(signed_zero) ? -1 : 1;
    // for each iteration, progressively decrement the argument by a scale of 0.001
    for(int i = 20; i>=0; i--){
        float x = 0.001*sign*i;
        full_log << "For x: " << x << "log(x) = " << log(x) << endl;
        
    }
    full_log.close();
}

// Observe sinc behaviour as x tends to +/-0
void signed_zero_sine_inverse( float signed_zero ){
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl << "------------ " << signed_zero << " behavior for sin(x)/x =  ------------" << endl;
    // check if the argument is signed
    float sign = signbit(signed_zero) ? -1 : 1;
    // for each iteration, progressively decrement the argument by a scare of 0.001
    for(int i = 20; i>=0; i--){
        float x = 0.001*sign*i;
        
        full_log << "For x: " << x << "sin(x)/x = " << sin(x)/x << endl;
        
    }
    full_log.close();
}

//Observe sinc behaviour as x tends to +/- 0 (with absolute x in the denominator)
void signed_zero_sine_abs_inverse( float signed_zero ){
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << endl << "------------ " << signed_zero << " behavior for sin(x)/|x| ------------" << endl;
    // check if the argument is signed
    float sign = signbit(signed_zero) ? -1 : 1;
    // for each iteration, progressively decrement the argument by a scare of 0.001
    for(int i = 20; i>=0; i--){
        float x = 0.001*sign*i;
        full_log << "For x: " << x << "sin(x)/|x| = " << sin(x)/abs(x) << endl;
    }
    full_log.close();
}

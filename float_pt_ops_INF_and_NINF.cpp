//
//  float_pt_ops_INF_and_NINF.cpp
//  Program1
//
//  Created by Ariana Bruno on 2/12/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "float_pt_ops_INF_and_NINF.hpp"
#include <limits>  //for the infinity();
#include <math.h> //for sin();

float inverse_func ( float x ){
    return 1.0/x;
}

float sine_func ( float x ){
    return sin(x); //should we conver this from radians to degrees?
}

float expon_func ( float x ){
    return exp(x);
}

// custom function to detect NINF 
bool detect_NINF( float NINF_input ){
	// first generate inf and ninf
    float NINF_generated = -1.0/0.0;
    float INF_generated = 1.0/0.0;
    
    // check if the input argument equals ninf, but not inf
    if (NINF_input == NINF_generated && NINF_input != INF_generated) {
        return true;
    } else {
        return false;
    }
}

// custom function ot detect INF
bool detect_INF( float INF_input ){
	// first generate inf and ninf
    float NINF_generated = -1.0/0.0;
    float INF_generated = 1.0/0.0;
    
    // check if the input argument equals inf, but not ninf
    if (INF_input != NINF_generated && INF_input == INF_generated) {
        return true;
    } else {
        return false;
    }
}

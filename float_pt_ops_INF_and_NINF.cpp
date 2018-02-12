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

//
//  float_pt_ops_INF_and_NINF.hpp
//  Program1
//
//  Created by Ariana Bruno on 2/12/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef float_pt_ops_INF_and_NINF_hpp
#define float_pt_ops_INF_and_NINF_hpp

#include <stdio.h>
#include <limits>  //for the infinity();
#include <math.h> //for sin();
#include <iostream>
#include <fstream>

using namespace std;

float inverse_func ( float x );
float sine_func ( float x );
float expon_func ( float x );

//**************************************
// test cases
//**************************************

void test_INF_functions();
void test_NINF_functions();
void test_INF_NINF_propogation();
bool detect_NINF( float NINF_input );
bool detect_INF( float INF_input );

#endif /* float_pt_ops_INF_and_NINF_hpp */

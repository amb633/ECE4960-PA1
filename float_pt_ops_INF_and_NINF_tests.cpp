//
//  float_pt_ops_INF_NINF_tests.cpp
//  Program1
//
//  Created by Ariana Bruno on 2/12/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//


#include "float_pt_ops_INF_and_NINF.hpp"

void test_INF_functions(){
    float INF = numeric_limits<float>::infinity();

    cout<< "Trying the inverse, sine, and exponential function for INF first: " << endl;

    cout << "This is 1/INF: " << inverse_func(INF) << endl;
    cout << "This is sin(INF): " << sine_func(INF) << endl;
    cout << "This is e^INF: "  << expon_func(INF) << endl;
}

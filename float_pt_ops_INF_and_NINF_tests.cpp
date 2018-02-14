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

    cout << "This is 1/INF: " << inverse_func(INF) << endl;
    cout << "This is sin(INF): " << sine_func(INF) << endl;
    cout << "This is e^INF: "  << expon_func(INF) << endl;
}

void test_NINF_functions(){
    float NINF = -1*numeric_limits<float>::infinity();
    
    cout << "1/NINF= " << inverse_func(NINF) << endl;
    cout << "sin(NINF)= " << sine_func(NINF) << endl;
    cout << "e^NINF= "  << expon_func(NINF) << endl;
}

void test_INF_NINF_propogation(){
    float INF = numeric_limits<float>::infinity();
    float NINF = -1*numeric_limits<float>::infinity();
    
    cout << "INF + NINF = " << INF + NINF << endl;
    cout << "INF - NINF = " << INF - NINF << endl;
    cout << "NINF - INF = "  << NINF - INF << endl;
    cout << "INF*INF = "  << INF*INF << endl;
    cout << "INF*NINF = "  << INF*NINF << endl;
    cout << "NINF*NINF = "  << NINF*NINF << endl;
    cout << "INF/INF = "  << INF/INF << endl;
    cout << "NINF/INF = "  << NINF/INF << endl;
    cout << "INF/NINF = "  << INF/NINF << endl;
    cout << "NINF/NINF = "  << NINF/NINF << endl;
    cout << "INF^NINF = "  << pow(INF, NINF) << endl;
    cout << "NINF^INF = "  << pow(NINF, INF) << endl;
    
}

bool detect_NINF( float NINF_input ){
    float NINF_generated = -1.0/0.0;
    float INF_generated = 1.0/0.0;
    
    if (NINF_input == NINF_generated && NINF_input != INF_generated) {
        return true;
    } else {
        return false;
    }
}

bool detect_INF( float INF_input ){
    float NINF_generated = -1.0/0.0;
    float INF_generated = 1.0/0.0;
    
    if (INF_input != NINF_generated && INF_input == INF_generated) {
        return true;
    } else {
        return false;
    }
}

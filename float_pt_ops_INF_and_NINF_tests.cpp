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

void test_INF_NINF_detection(){
    float INF = numeric_limits<float>::infinity();
    float NINF = -1*numeric_limits<float>::infinity();
    
    cout << "Detection of INF of isinf(INF): " << isinf(INF) << endl;
    cout << "Detection of INF of isinf(NINF): " << isinf(NINF) << endl;
    cout << "Detection of INF of isinf(log(0.0)): " << isinf(log(0.0)) << endl;
    cout << "Detection of INF of isinf(exp(pow(10,20)): " << isinf(exp(pow(10,20))) << endl;
}

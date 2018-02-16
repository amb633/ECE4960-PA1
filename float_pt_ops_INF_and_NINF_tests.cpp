//
//  float_pt_ops_INF_NINF_tests.cpp
//  Program1
//
//  Created by Ariana Bruno on 2/12/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//


#include "float_pt_ops_INF_and_NINF.hpp"

// observe how arithmetic operations work on INF
void test_INF_functions(){
    float INF = numeric_limits<float>::infinity();
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);

    full_log << "This is 1/INF: " << inverse_func(INF) << endl;
    full_log << "This is sin(INF): " << sine_func(INF) << endl;
    full_log << "This is e^INF: "  << expon_func(INF) << endl;
    full_log.close();
}

// observe how arithmetic operations work on NINF
void test_NINF_functions(){
    float NINF = -1*numeric_limits<float>::infinity();
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << "1/NINF= " << inverse_func(NINF) << endl;
    full_log << "sin(NINF)= " << sine_func(NINF) << endl;
    full_log << "e^NINF= "  << expon_func(NINF) << endl;
    full_log.close();
}

// observe how INF and NINF are propagated to other variables through arithmetic operations
void test_INF_NINF_propogation(){
    float INF = numeric_limits<float>::infinity();
    float NINF = -1*numeric_limits<float>::infinity();
    ofstream full_log;
    full_log.open ("full_log_output.txt", ios_base::app | ios_base::out);
    full_log << "INF + NINF = " << INF + NINF << endl;
    full_log << "INF - NINF = " << INF - NINF << endl;
    full_log << "NINF - INF = "  << NINF - INF << endl;
    full_log << "INF*INF = "  << INF*INF << endl;
    full_log << "INF*NINF = "  << INF*NINF << endl;
    full_log << "NINF*NINF = "  << NINF*NINF << endl;
    full_log << "INF/INF = "  << INF/INF << endl;
    full_log << "NINF/INF = "  << NINF/INF << endl;
    full_log << "INF/NINF = "  << INF/NINF << endl;
    full_log << "NINF/NINF = "  << NINF/NINF << endl;
    full_log << "INF^NINF = "  << pow(INF, NINF) << endl;
    full_log << "NINF^INF = "  << pow(NINF, INF) << endl;
    full_log.close();
    
}
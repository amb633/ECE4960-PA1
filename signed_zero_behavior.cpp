//
//  signed_zero_behavior.cpp
//  Program1
//
//  Created by Ariana Bruno on 2/12/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "signed_zero_behavior.hpp"


void signed_zero_log( float signed_zero ){
    float sign = signbit(signed_zero) ? 1 : -1;
    for(int i = 20; i>=0; i--){
        float x = sign*i;
        cout << "For x: " << x << "log(x) = " << log(x) << endl;
    }
}

void signed_zero_sine_inverse( float signed_zero ){
    float sign = signbit(signed_zero) ? 1 : -1;
    
}

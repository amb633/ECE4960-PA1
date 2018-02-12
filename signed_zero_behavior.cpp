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
    //cout << sign << endl;
    for(int i = 20; i>=0; i--){
        float x = sign*i;
        cout << "For x: " << x << "log(x) = " << log(x) << endl;
    }
}

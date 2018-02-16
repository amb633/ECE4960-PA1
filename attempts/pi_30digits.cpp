//
//  pi_30digits.cpp
//  
//
//  Created by Ariana Bruno on 2/14/18.
//

#include "pi_30digits.hpp"

double bit_pi_equation( int n, int n_max ){
    
    double result = 0;
    for( double n = 0.0; n<=n_max; n++){
        double term1 = pow((-1.0),n)/pow(2.0,10.0*n);
        double term2 = -pow(2.0,5.0)/(4.0*n + 1.0);
        double term3 = -1.0/(4.0*n + 3.0);
        double term4 = pow(2.0,8.0)/(10.0*n +1.0);
        double term5 = -pow(2.0,6.0)/(10.0*n + 3.0);
        double term6 = -pow(2.0,2.0)/(10.0*n+5.0);
        double term7 = -pow(2.0,2.0)/(10.0*n+7.0);
        double term8 = 1.0/(10.0*n+9.0);
        double sum = (term2 + term3 + term4 + term5 + term6 + term7 + term8);
//        std::cout << "multiplier:   " << term1 << std::endl;
//        std::cout << "sum:    " << sum << std::endl;
//        std::cout << "iterative result:   " << (term1 * sum) << std::endl;
        result = result + (term1 * sum);
//        std::cout << "total result:   " << result << std::endl;
//        std::cout << std::endl;
    }
    return (1/pow(2,6))*result;
}

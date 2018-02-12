//
//
//Programming Assignment 1
//Collaboration by Ariana Bruno and Haritha Murali
//Due Wednesday 02/14/2018
//
//
//

#include "test_functions.hpp"
#include "int_div_0.hpp"
#include "float_pt_ops_INF_and_NINF.hpp"
#include <limits>  //for the infinity();

using namespace std;

int main() {
    
    //testing out that the function link between files works and compiles as expected
	cout << endl;

	factorial ( 20 );
	cout << endl;

	fibonacci( 50 );
	cout << endl;

	/*int int_zero;
	int zero = 0;

	try {
		int_zero = 2/zero;
		throw -1;
	}

	catch ( int err ) {
		cout << " error in divsion " << endl << endl;
	}*/
    
    //running this portion to create compiler exception for int divided by 0
    /*int err = int_div_0(5);
    cout << err << endl;*/
    
    float INF = std::numeric_limits<float>::infinity();
    float NINF = -1*INF;
    
    cout<< "Trying the inverse, sine, and exponential function for INF first: " << endl;
    
    cout << "This is 1/INF: " << inverse_func(INF) << endl;
    cout << "This is sin(INF): " << sine_func(INF) << endl;
    cout << "This is e^INF: "  << expon_func(INF) << endl;
    
    cout<< "Trying the inverse, sine, and exponential function for NINF second: " << endl;
    
    cout << "This is 1/NINF: " << inverse_func(NINF) << endl;
    cout << "This is sin(NINF): " << sine_func(NINF) << endl;
    cout << "This is e^NINF: "  << expon_func(NINF) << endl;
    
	return 0;
}


#include <cstdlib>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

/* Primary Functions
 * these functions illustrate different methods to generate a nan
 */
double sqrtNegative ( double x );
double logNegative( double x );
double infLessInf( );
double infDivideInf();

/* Secondary Functions
 * these functions perform arithmetic operations on nan variables
 * and check for performance stipulations 
 */
double addNan( double x , double y );
double multiplyNan( double x , double y );
double sineNan( double x );
double powerNan( double x , double y );
double infAndNan();

/* Custom function to detect Nan */
bool detectNan( double x );

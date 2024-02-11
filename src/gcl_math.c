#include "gcl_math.h"
#include <stdio.h>


// Bisection Method
// parameter a is used comparison
double gcl_bisectionRoot( gcl_AlgebraicParameter param, gcl_AlgebraicFunction func){
    double t, a, b;
    a = MAX(param.a, param.b), b = MIN(param.a, param.b);
    while(func(param) != 0){
        t = (a+b)/2;
        param.a = t;
        if (func(param) > 0){
            a = t;
            param.a = t;
        }
        else {
            b = t;
            param.a = t;
        }
    }
    return a;
}

// Newton - Raphson Method 
// paramater a -> xn the rest are not used except for the algebriac function
double gcl_newtonRoot(gcl_AlgebraicParameter param, gcl_AlgebraicFunction func, gcl_AlgebraicFunction func_prime, int n){
    if (n-- <= 0) {
        return param.a;
    }
    
    param.a = gcl_newtonRoot(param, func, func_prime, n); // record the results for xi
    double denominator = func_prime(param);
    if (denominator == 0) return param.a; // prevent 0 erors
    
    param.a = param.a - func(param)/denominator; // compute the iteration xi+1
    return param.a;
}

// Square Root Approximation
// Quadratic & its derivative to be used for sqrt approximation
// parameter a and c are used 
double gcl_quadratic_noLinear(gcl_AlgebraicParameter param){
    double c = param.a*param.a + param.c;
    return c;
}

// parameter a is used
double gcl_primeQuadratic_noLinear(gcl_AlgebraicParameter param){
    return 2*param.a;
}

// sqrt approximation using newton raphson method
double gcl_sqrt(double x, int n){
    gcl_AlgebraicParameter param;
    param.a = x;
    param.c = -1 * x;
    return gcl_newtonRoot(param, gcl_quadratic_noLinear, gcl_primeQuadratic_noLinear, n);
}

// Useful Functions
double gcl_crossProduct2D(double a1, double b1, double a2, double b2){
    return a1*b2 - a2 * b1;
}
    #ifdef __cplusplus
extern "C"{
#endif

#ifndef GCL_MATH_H
#define GCL_MATH_H
#include <math.h>

/*
#####################################################################
    Handles any mathematical function or algorithm like
    approximations and numerical methods

    - Root Finding Method
        - Bisection Method
        - Newton Raphson Method
    - Irrational Function
        - Roots
    
#####################################################################
*/

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CEIL(a) ((int)a) + 1
#define FLOOR(a) (int)a
#define ROUND(a) ((a-(int)a) >= 0.5 ? (CEIL(a)) : (FLOOR(a))) 
#define ABSF(a) ((a) < 0 ? (-1*a) : (a)) // Floating number use only for absolute
#define PYTHO2(x, y) x*x + y*y
#define PYTHO(x, y) gcl_sqrt(PYTHO2(x, y), 40)// Pythogorean w/ sqrt

// Mathemtical Approximation
typedef struct{
    double a, b, c;
    double* extra; // If more than 3 inputs
} gcl_AlgebraicParameter; // Used for pasting set of inputs for the equation
typedef double (*gcl_AlgebraicFunction)(gcl_AlgebraicParameter);

// Rational Functions
double gcl_quadratic_noLinear(gcl_AlgebraicParameter param);
double gcl_primeQuadratic_noLinear(gcl_AlgebraicParameter param);

// Root Finding Method

// Bisection Root Finding Method
// Intervals between [a, b] that has this following conditions
// a > b s.t a > 0 and b < 0 ( Applying Intermediate Theorem )
double gcl_bisectionRoot(gcl_AlgebraicParameter param, gcl_AlgebraicFunction func);

// Netwton Raphson Root Finding Method
// Recursive approximation of xi by number of iteration n
double gcl_newtonRoot(gcl_AlgebraicParameter param, gcl_AlgebraicFunction func, gcl_AlgebraicFunction func_prime, int n);

// Irrational Function
double gcl_sqrt(double x, int n);

// Useful Functions
double gcl_crossProduct2D(double a1, double b1, double a2, double b2);


#endif

#ifdef __cplusplus
}
#endif
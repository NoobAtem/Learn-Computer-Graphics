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

// Matrix & Vector
Vec gcl_vector_init(size_t size){
    Vec vector;
    vector.data = (float*)malloc(size*sizeof(float));
    if (vector.data == NULL){
        printf("Failed to Initilize Vector\n");
        return vector;
    }

    memset(vector.data, 0.0f, size*sizeof(float));
    vector.size = size;
    return vector;
}

Mat gcl_matrix_init(size_t row, size_t col){
    Mat matrix;
    for (size_t i = 0; i < row; i++){
        // Create Row Vectors
        matrix.vector = (Vec*)malloc(row*sizeof(Vec));
        *(matrix.vector+i) = gcl_vector_init(col);
    }
    matrix.size[0] = row;
    matrix.size[1] = col;
    return matrix;
}

void gcl_displayVector(Vec* vec){
    printf("[");
    if (vec->size > 0) printf("%f", vec->data[0]);
    for (size_t i = 1; i < vec->size; i++){
        printf(", %f", vec->data[i]);
    }
    printf("]\n");
}

void gcl_displayMatrix(Mat* mat){
    printf("[");
    for (size_t i = 0; i < mat->size[0]; i++){
        gcl_displayVector(&mat->vector[i]);
    }
    printf("]\n");
}

Vec gcl_vector_dot(Vec a, Vec b){
    if (a.size != b.size)
        return (Vec){NULL};
    Vec dot = gcl_vector_init(a.size);

    for (size_t i = 0; i < a.size; i++){
        float result = 0.0f;
        for (size_t j = 0; j < b.size; j++){
            result += a.data[i]*b.data[j];
        }
        dot.data[i] = result;
    }
    return dot;
}

float gcl_dot_product2D(float x, float y, float w, float z){
    return x*w - z*y;
}

int gcl_fact(int i){
   if(i < 1) return 0;
   return gcl_fact(i-1) + gcl_fact(i-2);
}

double gcl_comb(int n, int k){
    return gcl_fact(n)/(gcl_fact(k)*gcl_fact(n-k));
}

// Graphics Math
// Linear Interpolation
double gcl_lerp(double x0, double y0, double x1, double y1, double t){
    return y0 + t*(y1-y0)/(x1-x0);	
}

double gcl_recursive_bezier_curve(double t, double* x, double* y, int n){
    
}

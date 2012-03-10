
#include <math.h>
#include <stdio.h>
#include "cumlan.h"


int sgn(double x)
{
    return (x > 0) - (x < 0);
}


double invcumlan_(double *x, double *x0, double *xi)
{
    
    // Use bisection method to get close to root
        
    double u = *x;
    if (u <= 0)
    {
        return 0;
    }
    if (u > 1.)
    {
        u = 1.;
    }
    double a = (*x0) - fabs(20 * *xi);
    double b = (*x0) + fabs(50 * *xi);
    double fa = u - cumlan_(&a, x0, xi);
    double tol = 1E-8, c, fc, value;
    unsigned int maxiter = 100, i;
    
    for (i = 0; i <= maxiter; ++i)
    {
        // midpoint
        c = (a + b) / 2.;
        fc = u - cumlan_(&c, x0, xi); 
        // stopping criteria
        if (fc == 0 || (b - a) / 2. < tol)
        {
            break;
        }
        // shrink
        if (sgn(fc) == sgn(fa))
        {
            a = c;
            fa = fc;
        }
        else
        {
            b = c;
        }
    }
    
    // Use secant method to converge on root
    for (i = 0; i <= maxiter; ++i)
    {
        value = c - fc * (c - a) / (fc - fa);
        if (fabs(value - c) < tol)
        {
            break;
        }
        fa = fc;
        fc = u - cumlan_(&value, x0, xi);
        if (fc == 0)
        {
            break;
        }
        a = c;
        c = value;
    }
    if (value < 0)
    {
        return 0;
    }
    return value;
} /* invcumlan_ */

/* dislan.F -- translated by f2c (version 20090411).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"


/* $Id: dislan.F,v 1.1.1.1 1996/04/01 15:02:43 mclareni Exp $ */

/* $Log: dislan.F,v $ */
/* Revision 1.1.1.1  1996/04/01 15:02:43  mclareni */
/* Mathlib gen */


/*     This will be DISLAN,IF=DOUBLE and DISLAN64,IF=-DOUBLE */
doublereal dislan_(real *x, real *x0, real *xi)
{
    /* Initialized data */

    static real p1[5] = { .2514091491f,-.06250580444f,.0145838123f,
	    -.002108817737f,7.41124729e-4f };
    static real q5[4] = { 1.f,50.09928881f,139.9819104f,420.0002909f };
    static real p6[4] = { 1.000000983f,132.9868456f,916.2149244f,
	    -960.5054274f };
    static real q6[4] = { 1.f,133.9887843f,1055.990413f,553.2224619f };
    static real a1[3] = { -.4583333333f,.6675347222f,-1.641741416f };
    static real a2[3] = { 1.f,-.4227843351f,-2.043403138f };
    static real q1[5] = { 1.f,-.005571175625f,.06225310236f,-.003137378427f,
	    .001931496439f };
    static real p2[4] = { .2868328584f,.3564363231f,.1523518695f,
	    .02251304883f };
    static real q2[4] = { 1.f,.6191136137f,.1720721448f,.02278594771f };
    static real p3[4] = { .2868329066f,.3003828436f,.09950951941f,
	    .008733827185f };
    static real q3[4] = { 1.f,.4237190502f,.1095631512f,.008693851567f };
    static real p4[4] = { 1.00035163f,4.503592498f,10.8588388f,7.536052269f };
    static real q4[4] = { 1.f,5.539969678f,19.33581111f,27.21321508f };
    static real p5[4] = { 1.000006517f,49.09414111f,85.05544753f,153.2153455f 
	    };

    /* System generated locals */
    real ret_val;

    /* Builtin functions */
    double exp(doublereal), sqrt(doublereal), log(doublereal);

    /* Local variables */
    static real u, v;

    if (*xi <= 0.f) {
	ret_val = 0.f;
	return ret_val;
    }
    v = (*x - *x0) / *xi;
    if (v < -5.5f) {
	u = exp(v + 1);
	ret_val = exp(-1 / u) * .3989422803f * sqrt(u) * ((a1[0] + (a1[1] + 
		a1[2] * u) * u) * u + 1);
    } else if (v < -1.f) {
	u = exp(-v - 1);
	ret_val = exp(-u) / sqrt(u) * (p1[0] + (p1[1] + (p1[2] + (p1[3] + p1[
		4] * v) * v) * v) * v) / (q1[0] + (q1[1] + (q1[2] + (q1[3] + 
		q1[4] * v) * v) * v) * v);
    } else if (v < 1.f) {
	ret_val = (p2[0] + (p2[1] + (p2[2] + p2[3] * v) * v) * v) / (q2[0] + (
		q2[1] + (q2[2] + q2[3] * v) * v) * v);
    } else if (v < 4.f) {
	ret_val = (p3[0] + (p3[1] + (p3[2] + p3[3] * v) * v) * v) / (q3[0] + (
		q3[1] + (q3[2] + q3[3] * v) * v) * v);
    } else if (v < 12.f) {
	u = 1 / v;
	ret_val = (p4[0] + (p4[1] + (p4[2] + p4[3] * u) * u) * u) / (q4[0] + (
		q4[1] + (q4[2] + q4[3] * u) * u) * u);
    } else if (v < 50.f) {
	u = 1 / v;
	ret_val = (p5[0] + (p5[1] + (p5[2] + p5[3] * u) * u) * u) / (q5[0] + (
		q5[1] + (q5[2] + q5[3] * u) * u) * u);
    } else if (v < 300.f) {
	u = 1 / v;
	ret_val = (p6[0] + (p6[1] + (p6[2] + p6[3] * u) * u) * u) / (q6[0] + (
		q6[1] + (q6[2] + q6[3] * u) * u) * u);
    } else {
	u = 1 / (v - v * log(v) / (v + 1));
	ret_val = 1 - (a2[0] + (a2[1] + a2[2] * u) * u) * u;
    }
    return ret_val;
} /* dislan_ */


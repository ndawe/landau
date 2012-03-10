/* denlan.F -- translated by f2c (version 20090411).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include <math.h>

/* $Id: denlan.F,v 1.1.1.1 1996/04/01 15:02:43 mclareni Exp $ */

/* $Log: denlan.F,v $ */
/* Revision 1.1.1.1  1996/04/01 15:02:43  mclareni */
/* Mathlib gen */


/*     This will be DENLAN,IF=DOUBLE and DENLAN64,IF=-DOUBLE */
doubledouble denlan_(real *x, real *x0, real *xi)
{
    /* Initialized data */

    static double p1[5] = { .4259894875f,-.124976255f,.039842437f,
	    -.006298287635f,.001511162253f };
    static double q5[5] = { 1.f,156.9424537f,3745.310488f,9834.698876f,
	    66924.28357f };
    static double p6[5] = { 1.000827619f,664.9143136f,62972.92665f,475554.6998f,
	    -5743609.109f };
    static double q6[5] = { 1.f,651.4101098f,56974.73333f,165917.4725f,
	    -2815759.939f };
    static double a1[3] = { .04166666667f,-.01996527778f,.02709538966f };
    static double a2[2] = { -1.84556867f,-4.284640743f };
    static double q1[5] = { 1.f,-.3388260629f,.09594393323f,-.01608042283f,
	    .003778942063f };
    static double p2[5] = { .1788541609f,.1173957403f,.01488850518f,
	    -.001394989411f,1.283617211e-4f };
    static double q2[5] = { 1.f,.7428795082f,.3153932961f,.06694219548f,
	    .008790609714f };
    static double p3[5] = { .1788544503f,.09359161662f,.006325387654f,
	    6.611667319e-5f,-2.031049101e-6f };
    static double q3[5] = { 1.f,.6097809921f,.2560616665f,.04746722384f,
	    .006957301675f };
    static double p4[5] = { .9874054407f,118.6723273f,849.279436f,-743.7792444f,
	    427.0262186f };
    static double q4[5] = { 1.f,106.8615961f,337.6496214f,2016.712389f,
	    1597.063511f };
    static double p5[5] = { 1.003675074f,167.5702434f,4789.711289f,21217.86767f,
	    -22324.9491f };

    /* System generated locals */
    double ret_val, r__1;

    /* Local variables */
    static double u, v;

    if (*xi <= 0.f) {
	ret_val = 0.f;
	return ret_val;
    }
    v = (*x - *x0) / *xi;
    if (v < -5.5f) {
	u = exp(v + 1.f);
	ret_val = exp(-1 / u) / sqrt(u) * .3989422803f * ((a1[0] + (a1[1] + 
		a1[2] * u) * u) * u + 1);
    } else if (v < -1.f) {
	u = exp(-v - 1);
	ret_val = exp(-u) * sqrt(u) * (p1[0] + (p1[1] + (p1[2] + (p1[3] + p1[
		4] * v) * v) * v) * v) / (q1[0] + (q1[1] + (q1[2] + (q1[3] + 
		q1[4] * v) * v) * v) * v);
    } else if (v < 1.f) {
	ret_val = (p2[0] + (p2[1] + (p2[2] + (p2[3] + p2[4] * v) * v) * v) * 
		v) / (q2[0] + (q2[1] + (q2[2] + (q2[3] + q2[4] * v) * v) * v) 
		* v);
    } else if (v < 5.f) {
	ret_val = (p3[0] + (p3[1] + (p3[2] + (p3[3] + p3[4] * v) * v) * v) * 
		v) / (q3[0] + (q3[1] + (q3[2] + (q3[3] + q3[4] * v) * v) * v) 
		* v);
    } else if (v < 12.f) {
	u = 1 / v;
/* Computing 2nd power */
	r__1 = u;
	ret_val = r__1 * r__1 * (p4[0] + (p4[1] + (p4[2] + (p4[3] + p4[4] * u)
		 * u) * u) * u) / (q4[0] + (q4[1] + (q4[2] + (q4[3] + q4[4] * 
		u) * u) * u) * u);
    } else if (v < 50.f) {
	u = 1 / v;
/* Computing 2nd power */
	r__1 = u;
	ret_val = r__1 * r__1 * (p5[0] + (p5[1] + (p5[2] + (p5[3] + p5[4] * u)
		 * u) * u) * u) / (q5[0] + (q5[1] + (q5[2] + (q5[3] + q5[4] * 
		u) * u) * u) * u);
    } else if (v < 300.f) {
	u = 1 / v;
/* Computing 2nd power */
	r__1 = u;
	ret_val = r__1 * r__1 * (p6[0] + (p6[1] + (p6[2] + (p6[3] + p6[4] * u)
		 * u) * u) * u) / (q6[0] + (q6[1] + (q6[2] + (q6[3] + q6[4] * 
		u) * u) * u) * u);
    } else {
	u = 1 / (v - v * log(v) / (v + 1));
/* Computing 2nd power */
	r__1 = u;
	ret_val = r__1 * r__1 * ((a2[0] + a2[1] * u) * u + 1);
    }
    return ret_val;
} /* denlan_ */


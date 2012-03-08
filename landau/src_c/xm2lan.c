/* xm2lan.F -- translated by f2c (version 20090411).
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


/* $Id: xm2lan.F,v 1.1.1.1 1996/04/01 15:02:45 mclareni Exp $ */

/* $Log: xm2lan.F,v $ */
/* Revision 1.1.1.1  1996/04/01 15:02:45  mclareni */
/* Mathlib gen */


/*     This will be XM2LAN,IF=DOUBLE and XM2LAN64,IF=-DOUBLE */
doublereal xm2lan_(real *x, real *x0, real *xi)
{
    /* Initialized data */

    static real p1[5] = { 1.169837582f,-.4834874539f,.4383774644f,
	    .003287175228f,.01879129206f };
    static real q5[4] = { 1.f,360.5950254f,13927.84158f,-18816.80027f };
    static real a0[7] = { -2.043403138f,-.8455686702f,-.3088626596f,
	    5.821346754f,.4227843351f,6.552993748f,-10.76714945f };
    static real a1[3] = { -.4583333333f,.6675347222f,-1.641741416f };
    static real a2[4] = { -1.958333333f,5.563368056f,-21.11352961f,
	    100.6946266f };
    static real a3[4] = { -1.f,4.458333333f,-21.16753472f,116.3674359f };
    static real q1[5] = { 1.f,.1795154326f,.04612795899f,.002183459337f,
	    7.226623623e-5f };
    static real p2[5] = { 1.157939823f,-.3842809495f,.3317532899f,
	    .03547606781f,.006725645279f };
    static real q2[5] = { 1.f,.2916824021f,.0525985348f,.003840011061f,
	    9.950324173e-5f };
    static real p3[4] = { 1.178191282f,10.11623342f,-12.85585291f,
	    36.41361437f };
    static real q3[4] = { 1.f,8.614160194f,31.1892963f,.15143513f };
    static real p4[5] = { 1.030763698f,121.675866f,1637.431386f,-2171.466507f,
	    7010.168358f };
    static real q4[5] = { 1.f,102.2487911f,1377.64635f,3699.184961f,
	    4251.31561f };
    static real p5[4] = { 1.010084827f,394.4224824f,17730.25353f,
	    -70759.63938f };

    /* System generated locals */
    real ret_val, r__1, r__2, r__3;

    /* Builtin functions */
    double exp(doublereal), log(doublereal);

    /* Local variables */
    static real u, v;

    if (*xi <= 0.f) {
	ret_val = 0.f;
	return ret_val;
    }
    v = (*x - *x0) / *xi;
    if (v < -4.5f) {
	u = exp(v + 1);
/* Computing 2nd power */
	r__1 = v;
/* Computing 2nd power */
	r__2 = u;
	ret_val = r__1 * r__1 - r__2 * r__2 * 2 * (v / u + a2[0] * v + a3[0] 
		+ (a2[1] * v + a3[1] + (a2[2] * v + a3[2] + (a2[3] * v + a3[3]
		) * u) * u) * u) / ((a1[0] + (a1[1] + a1[2] * u) * u) * u + 1)
		;
    } else if (v < -2.f) {
	ret_val = (p1[0] + (p1[1] + (p1[2] + (p1[3] + p1[4] * v) * v) * v) * 
		v) / (q1[0] + (q1[1] + (q1[2] + (q1[3] + q1[4] * v) * v) * v) 
		* v);
    } else if (v < 2.f) {
	ret_val = (p2[0] + (p2[1] + (p2[2] + (p2[3] + p2[4] * v) * v) * v) * 
		v) / (q2[0] + (q2[1] + (q2[2] + (q2[3] + q2[4] * v) * v) * v) 
		* v);
    } else if (v < 5.f) {
	u = 1 / v;
	ret_val = v * (p3[0] + (p3[1] + (p3[2] + p3[3] * u) * u) * u) / (q3[0]
		 + (q3[1] + (q3[2] + q3[3] * u) * u) * u);
    } else if (v < 50.f) {
	u = 1 / v;
	ret_val = v * (p4[0] + (p4[1] + (p4[2] + (p4[3] + p4[4] * u) * u) * u)
		 * u) / (q4[0] + (q4[1] + (q4[2] + (q4[3] + q4[4] * u) * u) * 
		u) * u);
    } else if (v < 200.f) {
	u = 1 / v;
	ret_val = v * (p5[0] + (p5[1] + (p5[2] + p5[3] * u) * u) * u) / (q5[0]
		 + (q5[1] + (q5[2] + q5[3] * u) * u) * u);
    } else {
	u = v - v * log(v) / (v + 1);
	v = 1 / (u - u * (u + log(u) - v) / (u + 1));
	u = -log(v);
/* Computing 2nd power */
	r__1 = u;
/* Computing 2nd power */
	r__2 = u;
/* Computing 2nd power */
	r__3 = u;
	ret_val = (1 / v + r__1 * r__1 + a0[0] + a0[1] * u + (-(r__2 * r__2) 
		+ a0[2] * u + a0[3] + (a0[4] * (r__3 * r__3) + a0[5] * u + a0[
		6]) * v) * v) / (1 - (1 - a0[4] * v) * v);
    }
    return ret_val;
} /* xm2lan_ */


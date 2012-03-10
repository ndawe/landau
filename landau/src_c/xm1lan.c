/* xm1lan.F -- translated by f2c (version 20090411).
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

/* $Id: xm1lan.F,v 1.1.1.1 1996/04/01 15:02:44 mclareni Exp $ */

/* $Log: xm1lan.F,v $ */
/* Revision 1.1.1.1  1996/04/01 15:02:44  mclareni */
/* Mathlib gen */


/*     This will be XM1LAN,IF=DOUBLE and XM1LAN64,IF=-DOUBLE */
double xm1lan_(double *x, double *x0, double *xi)
{
    /* Initialized data */

    static double p1[5] = { -.894937428f,.4631783434f,-.04053332915f,
	    .0158007556f,-.003423874194f };
    static double q5[4] = { 1.f,602.827594f,37169.62017f,36862.72898f };
    static double a0[6] = { -.4227843351f,-.1544313298f,.4227843351f,
	    3.276496874f,2.043403138f,-8.6812965f };
    static double a1[3] = { -.4583333333f,.6675347222f,-1.641741416f };
    static double a2[4] = { -1.958333333f,5.563368056f,-21.11352961f,
	    100.6946266f };
    static double q1[5] = { 1.f,.1002930749f,.03575271633f,-.001915882099f,
	    4.811072364e-5f };
    static double p2[5] = { -.8933384046f,.1161296496f,.120008294f,
	    .02185699725f,.002128892058f };
    static double q2[5] = { 1.f,.4935531886f,.1066347067f,.01250161833f,
	    5.494243254e-4f };
    static double p3[5] = { -.8933322067f,.2339544896f,.08257653222f,
	    .01411226998f,2.892240953e-4f };
    static double q3[5] = { 1.f,.3616538408f,.06628026743f,.004839298984f,
	    5.248310361e-5f };
    static double p4[4] = { .9358419425f,67.16831438f,-676.5069077f,
	    902.6661865f };
    static double q4[4] = { 1.f,77.52562854f,-563.7811998f,-551.3156752f };
    static double p5[4] = { .9489335583f,556.1246706f,32082.74617f,
	    -48899.26524f };

    /* System generated locals */
    double ret_val;

    /* Local variables */
    static double u, v;

    if (*xi <= 0.f) {
	ret_val = 0.f;
	return ret_val;
    }
    v = (*x - *x0) / *xi;
    if (v < -4.5f) {
	u = exp(v + 1);
	ret_val = v - u * ((a2[0] + (a2[1] + (a2[2] + a2[3] * u) * u) * u) * 
		u + 1) / ((a1[0] + (a1[1] + a1[2] * u) * u) * u + 1);
    } else if (v < -2.f) {
	ret_val = (p1[0] + (p1[1] + (p1[2] + (p1[3] + p1[4] * v) * v) * v) * 
		v) / (q1[0] + (q1[1] + (q1[2] + (q1[3] + q1[4] * v) * v) * v) 
		* v);
    } else if (v < 2.f) {
	ret_val = (p2[0] + (p2[1] + (p2[2] + (p2[3] + p2[4] * v) * v) * v) * 
		v) / (q2[0] + (q2[1] + (q2[2] + (q2[3] + q2[4] * v) * v) * v) 
		* v);
    } else if (v < 10.f) {
	ret_val = (p3[0] + (p3[1] + (p3[2] + (p3[3] + p3[4] * v) * v) * v) * 
		v) / (q3[0] + (q3[1] + (q3[2] + (q3[3] + q3[4] * v) * v) * v) 
		* v);
    } else if (v < 40.f) {
	u = 1 / v;
	ret_val = log(v) * (p4[0] + (p4[1] + (p4[2] + p4[3] * u) * u) * u) / (
		q4[0] + (q4[1] + (q4[2] + q4[3] * u) * u) * u);
    } else if (v < 200.f) {
	u = 1 / v;
	ret_val = log(v) * (p5[0] + (p5[1] + (p5[2] + p5[3] * u) * u) * u) / (
		q5[0] + (q5[1] + (q5[2] + q5[3] * u) * u) * u);
    } else {
	u = v - v * log(v) / (v + 1);
	v = 1 / (u - u * (u + log(u) - v) / (u + 1));
	u = -log(v);
	ret_val = (u + a0[0] + (-u + a0[1] + (a0[2] * u + a0[3] + (a0[4] * u 
		+ a0[5]) * v) * v) * v) / (1 - (1 - (a0[2] + a0[4] * v) * v) *
		 v);
    }
    return ret_val;
} /* xm1lan_ */



#include <math.h>

/* Table of constant values */

static double c_b2 = 1.5;


/* $Id: diflan.F,v 1.1.1.1 1996/04/01 15:02:43 mclareni Exp $ */

/* $Log: diflan.F,v $ */
/* Revision 1.1.1.1  1996/04/01 15:02:43  mclareni */
/* Mathlib gen */


/*     This will be DIFLAN,IF=DOUBLE and DIFLAN64,IF=-DOUBLE */
double diflan_(double *x, double *x0, double *xi)
{
    /* Initialized data */

    static double p1[5] = { -.03062016156f,-.1251424734f,-.0955142054f,
	    -.02694356206f,-.002617552485f };
    static double q5[5] = { 1.f,.9000329289f,34.61966768f,4.666893094f,
	    192.6464264f };
    static double p6[5] = { -2.012496309f,-274.8432206f,-5759.040086f,
	    -16000.68673f,53346.52087f };
    static double q6[5] = { 1.f,122.9570501f,1874.682285f,5678.02513f,
	    52823.54475f };
    static double p7[6] = { -2.001584932f,-2407.420185f,-545666.9704f,
	    -28170170.48f,-206439298.2f,904960599.4f };
    static double q7[6] = { 1.f,1182.929609f,255229.9337f,11392057.96f,
	    39347020.81f,210806908.7f };
    static double a1[6] = { -.4583333333f,8.680555556e-4f,-.002852527006f,
	    .005386892562f,-.01431207031f,.05062996176f };
    static double a2[3] = { -7.536706011f,-9.601856962f,171.4615239f };
    static double q1[5] = { 1.f,1.177746655f,.613099399f,.1572703422f,
	    .01726295027f };
    static double p2[5] = { -.01549126548f,-.07551222105f,-.02598623886f,
	    .005471270049f,.002152270275f };
    static double q2[5] = { 1.f,.9997460723f,.4988264176f,.1289104987f,
	    .0163963253f };
    static double p3[5] = { -.01547135743f,-.07304184799f,-.01534151353f,
	    .003568780079f,-9.296196751e-5f };
    static double q3[5] = { 1.f,.8394107748f,.412803683f,.1050222892f,
	    .0170089465f };
    static double p4[5] = { -.01546273317f,-.06856127408f,.004611267324f,
	    -2.549945537e-4f,5.876190635e-6f };
    static double q4[5] = { 1.f,.5453266037f,.2802511577f,.04749121515f,
	    .01096278827f };
    static double p5[5] = { 8.642027131e-6f,-7.474291951e-4f,.02935678494f,
	    -2.769695199f,-7.769542153f };

    /* System generated locals */
    double ret_val, r__1;
    double d__1;

    /* Local variables */
    static double u, v;

    if (*xi <= 0.f) {
	ret_val = 0.f;
	return ret_val;
    }
    v = (*x - *x0) / *xi;
    if (v < -2.6f) {
	u = exp(v + 1);
	d__1 = (double) u;
	ret_val = exp(-1 / u) / pow(d__1, c_b2) * .3989422803f * ((a1[0] 
		+ (a1[1] + (a1[2] + (a1[3] + (a1[4] + a1[5] * u) * u) * u) * 
		u) * u) * u + 1);
    } else if (v < -1.75f) {
	ret_val = (p1[0] + (p1[1] + (p1[2] + (p1[3] + p1[4] * v) * v) * v) * 
		v) / (q1[0] + (q1[1] + (q1[2] + (q1[3] + q1[4] * v) * v) * v) 
		* v);
    } else if (v < -1.25f) {
	ret_val = (p2[0] + (p2[1] + (p2[2] + (p2[3] + p2[4] * v) * v) * v) * 
		v) / (q2[0] + (q2[1] + (q2[2] + (q2[3] + q2[4] * v) * v) * v) 
		* v);
    } else if (v < .5f) {
	ret_val = (p3[0] + (p3[1] + (p3[2] + (p3[3] + p3[4] * v) * v) * v) * 
		v) / (q3[0] + (q3[1] + (q3[2] + (q3[3] + q3[4] * v) * v) * v) 
		* v);
    } else if (v < 5.f) {
	ret_val = (p4[0] + (p4[1] + (p4[2] + (p4[3] + p4[4] * v) * v) * v) * 
		v) / (q4[0] + (q4[1] + (q4[2] + (q4[3] + q4[4] * v) * v) * v) 
		* v);
    } else if (v < 15.f) {
	u = 1 / v;
	ret_val = (p5[0] + (p5[1] + (p5[2] + (p5[3] + p5[4] * u) * u) * u) * 
		u) / (q5[0] + (q5[1] + (q5[2] + (q5[3] + q5[4] * u) * u) * u) 
		* u);
    } else if (v < 50.f) {
	u = 1 / v;
/* Computing 3rd power */
	r__1 = u;
	ret_val = r__1 * (r__1 * r__1) * (p6[0] + (p6[1] + (p6[2] + (p6[3] + 
		p6[4] * u) * u) * u) * u) / (q6[0] + (q6[1] + (q6[2] + (q6[3] 
		+ q6[4] * u) * u) * u) * u);
    } else if (v < 300.f) {
	u = 1 / v;
/* Computing 3rd power */
	r__1 = u;
	ret_val = r__1 * (r__1 * r__1) * (p7[0] + (p7[1] + (p7[2] + (p7[3] + (
		p7[4] + p7[5] * u) * u) * u) * u) * u) / (q7[0] + (q7[1] + (
		q7[2] + (q7[3] + (q7[4] + q7[5] * u) * u) * u) * u) * u);
    } else {
	u = v - v * log(v) / (v + 1);
	u = 1 / (u - u * (u + log(u) - v) / (u + 1));
/* Computing 3rd power */
	r__1 = u;
	ret_val = -(r__1 * (r__1 * r__1)) * ((a2[0] + (a2[1] + a2[2] * u) * u)
		 * u + 2.f);
    }
    return ret_val;
} /* diflan_ */


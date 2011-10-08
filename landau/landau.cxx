// @(#)root/mathcore:$Id: ProbFuncMathCore.cxx 37551 2010-12-11 21:05:39Z moneta $
// Authors: L. Moneta, A. Zsenei   06/2005 

#include <limits>

double landau_den(double x, double xi, double x0) {
    // LANDAU pdf : algorithm from CERNLIB G110 denlan
    // same algorithm is used in GSL 

    static double p1[5] = {0.4259894875,-0.1249762550, 0.03984243700, -0.006298287635,   0.001511162253};
    static double q1[5] = {1.0         ,-0.3388260629, 0.09594393323, -0.01608042283,    0.003778942063};

    static double p2[5] = {0.1788541609, 0.1173957403, 0.01488850518, -0.001394989411,   0.0001283617211};
    static double q2[5] = {1.0         , 0.7428795082, 0.3153932961,   0.06694219548,    0.008790609714};

    static double p3[5] = {0.1788544503, 0.09359161662,0.006325387654, 0.00006611667319,-0.000002031049101};
    static double q3[5] = {1.0         , 0.6097809921, 0.2560616665,   0.04746722384,    0.006957301675};

    static double p4[5] = {0.9874054407, 118.6723273,  849.2794360,   -743.7792444,      427.0262186};
    static double q4[5] = {1.0         , 106.8615961,  337.6496214,    2016.712389,      1597.063511};

    static double p5[5] = {1.003675074,  167.5702434,  4789.711289,    21217.86767,     -22324.94910};
    static double q5[5] = {1.0         , 156.9424537,  3745.310488,    9834.698876,      66924.28357};

    static double p6[5] = {1.000827619,  664.9143136,  62972.92665,    475554.6998,     -5743609.109};
    static double q6[5] = {1.0         , 651.4101098,  56974.73333,    165917.4725,     -2815759.939};

    static double a1[3] = {0.04166666667,-0.01996527778, 0.02709538966};

    static double a2[2] = {-1.845568670,-4.284640743};

    if (xi <= 0) return 0; 
    double v = (x - x0)/xi;
    double u, ue, us, denlan;
    if (v < -5.5) {
        u   = std::exp(v+1.0);
        if (u < 1e-10) return 0.0;
        ue  = std::exp(-1/u);
        us  = std::sqrt(u);
        denlan = 0.3989422803*(ue/us)*(1+(a1[0]+(a1[1]+a1[2]*u)*u)*u);
    } else if(v < -1) {
        u   = std::exp(-v-1);
        denlan = std::exp(-u)*std::sqrt(u)*
            (p1[0]+(p1[1]+(p1[2]+(p1[3]+p1[4]*v)*v)*v)*v)/
            (q1[0]+(q1[1]+(q1[2]+(q1[3]+q1[4]*v)*v)*v)*v);
    } else if(v < 1) {
        denlan = (p2[0]+(p2[1]+(p2[2]+(p2[3]+p2[4]*v)*v)*v)*v)/
            (q2[0]+(q2[1]+(q2[2]+(q2[3]+q2[4]*v)*v)*v)*v);
    } else if(v < 5) {
        denlan = (p3[0]+(p3[1]+(p3[2]+(p3[3]+p3[4]*v)*v)*v)*v)/
            (q3[0]+(q3[1]+(q3[2]+(q3[3]+q3[4]*v)*v)*v)*v);
    } else if(v < 12) {
        u   = 1/v;
        denlan = u*u*(p4[0]+(p4[1]+(p4[2]+(p4[3]+p4[4]*u)*u)*u)*u)/
            (q4[0]+(q4[1]+(q4[2]+(q4[3]+q4[4]*u)*u)*u)*u);
    } else if(v < 50) {
        u   = 1/v;
        denlan = u*u*(p5[0]+(p5[1]+(p5[2]+(p5[3]+p5[4]*u)*u)*u)*u)/
            (q5[0]+(q5[1]+(q5[2]+(q5[3]+q5[4]*u)*u)*u)*u);
    } else if(v < 300) {
        u   = 1/v;
        denlan = u*u*(p6[0]+(p6[1]+(p6[2]+(p6[3]+p6[4]*u)*u)*u)*u)/
            (q6[0]+(q6[1]+(q6[2]+(q6[3]+q6[4]*u)*u)*u)*u);
    } else {
        u   = 1/(v-v*std::log(v)/(v+1));
        denlan = u*u*(1+(a2[0]+a2[1]*u)*u);
    }
    return denlan/xi;
}


double landau_dis(double x, double xi, double x0) { 
    // implementation of landau distribution (from DISLAN)
    //The algorithm was taken from the Cernlib function dislan(G110)
    //Reference: K.S.Kolbig and B.Schorr, "A program package for the Landau
    //distribution", Computer Phys.Comm., 31(1984), 97-111

    static double p1[5] = {0.2514091491e+0,-0.6250580444e-1, 0.1458381230e-1, -0.2108817737e-2, 0.7411247290e-3};
    static double q1[5] = {1.0            ,-0.5571175625e-2, 0.6225310236e-1, -0.3137378427e-2, 0.1931496439e-2};

    static double p2[4] = {0.2868328584e+0, 0.3564363231e+0, 0.1523518695e+0, 0.2251304883e-1};
    static double q2[4] = {1.0            , 0.6191136137e+0, 0.1720721448e+0, 0.2278594771e-1};

    static double p3[4] = {0.2868329066e+0, 0.3003828436e+0, 0.9950951941e-1, 0.8733827185e-2};
    static double q3[4] = {1.0            , 0.4237190502e+0, 0.1095631512e+0, 0.8693851567e-2};

    static double p4[4] = {0.1000351630e+1, 0.4503592498e+1, 0.1085883880e+2, 0.7536052269e+1};
    static double q4[4] = {1.0            , 0.5539969678e+1, 0.1933581111e+2, 0.2721321508e+2};

    static double p5[4] = {0.1000006517e+1, 0.4909414111e+2, 0.8505544753e+2, 0.1532153455e+3};
    static double q5[4] = {1.0            , 0.5009928881e+2, 0.1399819104e+3, 0.4200002909e+3};

    static double p6[4] = {0.1000000983e+1, 0.1329868456e+3, 0.9162149244e+3, -0.9605054274e+3};
    static double q6[4] = {1.0            , 0.1339887843e+3, 0.1055990413e+4, 0.5532224619e+3};

    static double a1[4] = {0, -0.4583333333e+0, 0.6675347222e+0,-0.1641741416e+1};

    static double a2[4] = {0,  1.0            ,-0.4227843351e+0,-0.2043403138e+1};

    double v = (x - x0)/xi; 
    double u;
    double lan;

    if (v < -5.5) {
        u = std::exp(v+1);
        lan = 0.3989422803*std::exp(-1./u)*std::sqrt(u)*(1+(a1[1]+(a1[2]+a1[3]*u)*u)*u);
    }
    else if (v < -1 ) {
        u = std::exp(-v-1);
        lan = (std::exp(-u)/std::sqrt(u))*(p1[0]+(p1[1]+(p1[2]+(p1[3]+p1[4]*v)*v)*v)*v)/
            (q1[0]+(q1[1]+(q1[2]+(q1[3]+q1[4]*v)*v)*v)*v);
    }
    else if (v < 1)
        lan = (p2[0]+(p2[1]+(p2[2]+p2[3]*v)*v)*v)/(q2[0]+(q2[1]+(q2[2]+q2[3]*v)*v)*v);
    else if (v < 4)
        lan = (p3[0]+(p3[1]+(p3[2]+p3[3]*v)*v)*v)/(q3[0]+(q3[1]+(q3[2]+q3[3]*v)*v)*v);
    else if (v < 12) {
        u = 1./v;
        lan = (p4[0]+(p4[1]+(p4[2]+p4[3]*u)*u)*u)/(q4[0]+(q4[1]+(q4[2]+q4[3]*u)*u)*u);
    }
    else if (v < 50) {
        u = 1./v;
        lan = (p5[0]+(p5[1]+(p5[2]+p5[3]*u)*u)*u)/(q5[0]+(q5[1]+(q5[2]+q5[3]*u)*u)*u);
    }
    else if (v < 300) {
        u = 1./v;
        lan = (p6[0]+(p6[1]+(p6[2]+p6[3]*u)*u)*u)/(q6[0]+(q6[1]+(q6[2]+q6[3]*u)*u)*u);
    }
    else {
        u = 1./(v-v*std::log(v)/(v+1));
        lan = 1-(a2[1]+(a2[2]+a2[3]*u)*u)*u;
    }
    return lan;

}


double landau_xm1(double x, double xi, double x0) {
    // implementation of first momentum of Landau distribution
    // translated from Cernlib (XM1LAN function) by Benno List  

    static double p1[5] = {
        -0.8949374280E+0, 0.4631783434E+0,-0.4053332915E-1,
        0.1580075560E-1,-0.3423874194E-2};
    static double q1[5] = {
        1.0            , 0.1002930749E+0, 0.3575271633E-1,
        -0.1915882099E-2, 0.4811072364E-4};
    static double p2[5] = {
        -0.8933384046E+0, 0.1161296496E+0, 0.1200082940E+0,
        0.2185699725E-1, 0.2128892058E-2};
    static double q2[5] = {
        1.0            , 0.4935531886E+0, 0.1066347067E+0,
        0.1250161833E-1, 0.5494243254E-3};
    static double p3[5] = {
        -0.8933322067E+0, 0.2339544896E+0, 0.8257653222E-1,
        0.1411226998E-1, 0.2892240953E-3};
    static double q3[5] = {
        1.0            , 0.3616538408E+0, 0.6628026743E-1,
        0.4839298984E-2, 0.5248310361E-4};
    static double p4[4] = {
        0.9358419425E+0, 0.6716831438E+2,-0.6765069077E+3,
        0.9026661865E+3};
    static double q4[4] = {
        1.0            , 0.7752562854E+2,-0.5637811998E+3,
        -0.5513156752E+3};
    static double p5[4] = {
        0.9489335583E+0, 0.5561246706E+3, 0.3208274617E+5,
        -0.4889926524E+5};
    static double q5[4] = {
        1.0            , 0.6028275940E+3, 0.3716962017E+5,
        0.3686272898E+5};
    static double a0[6] = {
        -0.4227843351E+0,-0.1544313298E+0, 0.4227843351E+0,
        0.3276496874E+1, 0.2043403138E+1,-0.8681296500E+1};
    static double a1[4] = {0,
        -0.4583333333E+0, 0.6675347222E+0,-0.1641741416E+1};
    static double a2[5] = {0,
        -0.1958333333E+1, 0.5563368056E+1,-0.2111352961E+2,
        0.1006946266E+3};

    double v = (x-x0)/xi;
    double xm1lan;
    if (v < -4.5) {
        double u = std::exp(v+1);
        xm1lan = v-u*(1+(a2[1]+(a2[2]+(a2[3]+a2[4]*u)*u)*u)*u)/
            (1+(a1[1]+(a1[2]+a1[3]*u)*u)*u);
    } else if(v < -2) {
        xm1lan = (p1[0]+(p1[1]+(p1[2]+(p1[3]+p1[4]*v)*v)*v)*v)/
            (q1[0]+(q1[1]+(q1[2]+(q1[3]+q1[4]*v)*v)*v)*v);
    } else if(v < 2) {
        xm1lan = (p2[0]+(p2[1]+(p2[2]+(p2[3]+p2[4]*v)*v)*v)*v)/
            (q2[0]+(q2[1]+(q2[2]+(q2[3]+q2[4]*v)*v)*v)*v);
    } else if(v < 10) {
        xm1lan = (p3[0]+(p3[1]+(p3[2]+(p3[3]+p3[4]*v)*v)*v)*v)/
            (q3[0]+(q3[1]+(q3[2]+(q3[3]+q3[4]*v)*v)*v)*v);
    } else if(v < 40) {
        double u = 1/v;
        xm1lan = std::log(v)*(p4[0]+(p4[1]+(p4[2]+p4[3]*u)*u)*u)/
            (q4[0]+(q4[1]+(q4[2]+q4[3]*u)*u)*u);
    } else if(v < 200) {
        double u = 1/v;
        xm1lan= std::log(v)*(p5[0]+(p5[1]+(p5[2]+p5[3]*u)*u)*u)/
            (q5[0]+(q5[1]+(q5[2]+q5[3]*u)*u)*u);
    } else {
        double u = v-v*std::log(v)/(v+1);
        v = 1/(u-u*(u+ std::log(u)-v)/(u+1));
        u = -std::log(v);
        xm1lan = (u+a0[0]+(-u+a0[1]+(a0[2]*u+a0[3]+(a0[4]*u+a0[5])*v)*v)*v)/
            (1-(1-(a0[2]+a0[4]*v)*v)*v);
    }
    return xm1lan*xi + x0;
}


double landau_xm2(double x, double xi, double x0) {
    // implementation of second momentum of Landau distribution
    // translated from Cernlib (XM2LAN function) by Benno List  

    static double p1[5] = {
        0.1169837582E+1,-0.4834874539E+0, 0.4383774644E+0,
        0.3287175228E-2, 0.1879129206E-1};
    static double q1[5] = {
        1.0            , 0.1795154326E+0, 0.4612795899E-1,
        0.2183459337E-2, 0.7226623623E-4};
    static double p2[5] = {
        0.1157939823E+1,-0.3842809495E+0, 0.3317532899E+0,
        0.3547606781E-1, 0.6725645279E-2};
    static double q2[5] = {
        1.0            , 0.2916824021E+0, 0.5259853480E-1,
        0.3840011061E-2, 0.9950324173E-4};
    static double p3[4] = {
        0.1178191282E+1, 0.1011623342E+2,-0.1285585291E+2,
        0.3641361437E+2};
    static double q3[4] = {
        1.0            , 0.8614160194E+1, 0.3118929630E+2,
        0.1514351300E+0};
    static double p4[5] = {
        0.1030763698E+1, 0.1216758660E+3, 0.1637431386E+4,
        -0.2171466507E+4, 0.7010168358E+4};
    static double q4[5] = {
        1.0            , 0.1022487911E+3, 0.1377646350E+4,
        0.3699184961E+4, 0.4251315610E+4};
    static double p5[4] = {
        0.1010084827E+1, 0.3944224824E+3, 0.1773025353E+5,
        -0.7075963938E+5};
    static double q5[4] = {
        1.0            , 0.3605950254E+3, 0.1392784158E+5,
        -0.1881680027E+5};
    static double a0[7] = {
        -0.2043403138E+1,-0.8455686702E+0,-0.3088626596E+0,
        0.5821346754E+1, 0.4227843351E+0, 0.6552993748E+1,
        -0.1076714945E+2};
    static double a1[4] = {0,
        -0.4583333333E+0, 0.6675347222E+0,-0.1641741416E+1};
    static double a2[4] = {
        -0.1958333333E+1, 0.5563368056E+1,-0.2111352961E+2,
        0.1006946266E+3};
    static double a3[4] = {
        -1.0            , 0.4458333333E+1,-0.2116753472E+2,
        0.1163674359E+3};

    double v = (x-x0)/xi;
    double xm2lan;
    if (v < -4.5) {
        double u = std::exp(v+1);
        xm2lan = v*v-2*u*u*
            (v/u+a2[0]*v+a3[0]+(a2[1]*v+a3[1]+(a2[2]*v+a3[2]+
                                               (a2[3]*v+a3[3])*u)*u)*u)/
            (1+(a1[1]+(a1[2]+a1[3]*u)*u)*u);
    } else if (v < -2) {
        xm2lan = (p1[0]+(p1[1]+(p1[2]+(p1[3]+p1[4]*v)*v)*v)*v)/
            (q1[0]+(q1[1]+(q1[2]+(q1[3]+q1[4]*v)*v)*v)*v);
    } else if (v < 2) {
        xm2lan = (p2[0]+(p2[1]+(p2[2]+(p2[3]+p2[4]*v)*v)*v)*v)/
            (q2[0]+(q2[1]+(q2[2]+(q2[3]+q2[4]*v)*v)*v)*v);
    } else if (v < 5) {
        double u = 1/v;
        xm2lan = v*(p3[0]+(p3[1]+(p3[2]+p3[3]*u)*u)*u)/
            (q3[0]+(q3[1]+(q3[2]+q3[3]*u)*u)*u);
    } else if (v < 50) {
        double u = 1/v;
        xm2lan = v*(p4[0]+(p4[1]+(p4[2]+(p4[3]+p4[4]*u)*u)*u)*u)/
            (q4[0]+(q4[1]+(q4[2]+(q4[3]+q4[4]*u)*u)*u)*u);
    } else if (v < 200) {
        double u = 1/v;
        xm2lan = v*(p5[0]+(p5[1]+(p5[2]+p5[3]*u)*u)*u)/
            (q5[0]+(q5[1]+(q5[2]+q5[3]*u)*u)*u);
    } else { 
        double u = v-v*std::log(v)/(v+1);
        v = 1/(u-u*(u+log(u)-v)/(u+1));
        u = -std::log(v);
        xm2lan = (1/v+u*u+a0[0]+a0[1]*u+(-u*u+a0[2]*u+a0[3]+
                    (a0[4]*u*u+a0[5]*u+a0[6])*v)*v)/(1-(1-a0[4]*v)*v);
    }
    if (x0 == 0) return xm2lan*xi*xi;
    double xm1lan = landau_xm1(x, xi, x0);
    return xm2lan*xi*xi + (2*xm1lan-x0)*x0;
}

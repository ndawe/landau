
cdef extern double denlan_(double*, double*, double*)

cdef extern double dislan_(double*, double*, double*)

cdef extern double diflan_(double*, double*, double*)

cdef extern double ranlan_(double*)

cdef extern double xm1lan_(double*, double*, double*)

cdef extern double xm2lan_(double*, double*, double*)


def denlan(double X, double mu, double c):

    return denlan_(&X, &mu, &c)

def dislan(double X, double mu, double c):

    return dislan_(&X, &mu, &c)

def diflan(double X, double mu, double c):

    return diflan_(&X, &mu, &c)

def xm1lan(double X, double mu, double c):

    return xm1lan_(&X, &mu, &c)

def xm2lan(double X, double mu, double c):

    return xm2lan_(&X, &mu, &c)

def ranlan(double X):

    return ranlan_(&X)

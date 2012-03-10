
import numpy as np
cimport numpy as np

ctypedef np.float64_t DTYPE_t
DTYPE = np.float64

cdef extern double denlan_(double*, double*, double*)

cdef extern double diflan_(double*, double*, double*)

cdef extern double cumlan_(double*, double*, double*)

cdef extern double invcumlan_(double*, double*, double*)

cdef extern double xm1lan_(double*, double*, double*)

cdef extern double xm2lan_(double*, double*, double*)


def denlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = denlan_(&X[i], &mu, &c)
    return out

def diflan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):

    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = diflan_(&X[i], &mu, &c)
    return out

def xm1lan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):

    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = xm1lan_(&X[i], &mu, &c)
    return out

def xm2lan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):

    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = xm2lan_(&X[i], &mu, &c)
    return out

def cumlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = cumlan_(&X[i], &mu, &c)
    return out

def invcumlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = invcumlan_(&X[i], &mu, &c)
    return out

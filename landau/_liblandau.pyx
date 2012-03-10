
import numpy as np
cimport numpy as np

ctypedef np.float64_t DTYPE_t
DTYPE = np.float64

cdef extern double denlan_(double*, double*, double*)

cdef extern double dislan_(double*, double*, double*)

cdef extern double diflan_(double*, double*, double*)

cdef extern double ranlan_(double*)

cdef extern double xm1lan_(double*, double*, double*)

cdef extern double xm2lan_(double*, double*, double*)


def denlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = denlan_(&X[i], &mu, &c)
    return out

def dislan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = dislan_(&X[i], &mu, &c)
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

def ranlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] X):

    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((X.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < X.shape[0]:
        out[i] = ranlan_(&X[i])
    return out

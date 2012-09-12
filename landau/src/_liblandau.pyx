
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


def _denlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] x, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((x.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < x.shape[0]:
        out[i] = denlan_(&x[i], &mu, &c)
    return out

def _diflan(np.ndarray[DTYPE_t, ndim=1, mode="c"] x, double mu, double c):

    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((x.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < x.shape[0]:
        out[i] = diflan_(&x[i], &mu, &c)
    return out

def _xm1lan(np.ndarray[DTYPE_t, ndim=1, mode="c"] x, double mu, double c):

    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((x.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < x.shape[0]:
        out[i] = xm1lan_(&x[i], &mu, &c)
    return out

def _xm2lan(np.ndarray[DTYPE_t, ndim=1, mode="c"] x, double mu, double c):

    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((x.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < x.shape[0]:
        out[i] = xm2lan_(&x[i], &mu, &c)
    return out

def _cumlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] x, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((x.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < x.shape[0]:
        out[i] = cumlan_(&x[i], &mu, &c)
    return out

def _invcumlan(np.ndarray[DTYPE_t, ndim=1, mode="c"] x, double mu, double c):
    
    cdef np.ndarray[DTYPE_t, ndim=1] out \
            = np.empty((x.shape[0],), dtype=DTYPE, order='C')
    for i from 0 <= i < x.shape[0]:
        out[i] = invcumlan_(&x[i], &mu, &c)
    return out

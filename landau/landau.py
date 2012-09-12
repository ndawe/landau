import numpy as np
from ._liblandau import _denlan, _diflan, \
                        _cumlan, _invcumlan, \
                        _xm1lan, _xm2lan

DTYPE = np.float64

__all__ = [
    'denlan',
    'diflan',
    'cumlan',
    'invcumlan',
    'xm1lan',
    'xm2lan',
]


def denlan(x, mu, c):

    x = np.asarray(x, dtype=DTYPE)
    return _denlan(x, mu, c)


def diflan(x, mu, c):

    x = np.asarray(x, dtype=DTYPE)
    return _diflan(x, mu, c)


def cumlan(x, mu, c):

    x = np.asarray(x, dtype=DTYPE)
    return _cumlan(x, mu, c)


def invcumlan(x, mu, c):

    x = np.asarray(x, dtype=DTYPE)
    return _invcumlan(x, mu, c)


def xm1lan(x, mu, c):

    x = np.asarray(x, dtype=DTYPE)
    return _xm1lan(x, mu, c)


def xm2lan(x, mu, c):

    x = np.asarray(x, dtype=DTYPE)
    return _xm2lan(x, mu, c)

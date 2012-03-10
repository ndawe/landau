#!/usr/bin/env python

from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument('-m', type=float, default=2)
parser.add_argument('-c', type=float, default=.5)
args = parser.parse_args()

from matplotlib import pyplot as plt
import numpy as np
from landau import *

X = np.arange(0, 10, .001)

plt.figure()
plt.plot(X, diflan(X, args.m, args.c), label="diflan")
plt.plot(X, denlan(X, args.m, args.c), label="denlan")
plt.plot(X, dislan(X, args.m, args.c), label="dislan")
plt.legend()

plt.figure()
plt.plot(X, xm1lan(X, args.m, args.c), label="xm1lan")
plt.plot(X, xm2lan(X, args.m, args.c), label="xm2lan")
plt.legend()

X = np.arange(0, 1, .001)

plt.figure()
plt.plot(X, ranlan(X), label="ranlan")
plt.legend()
plt.show()

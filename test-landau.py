#!/usr/bin/env python

from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument('-mu', type=float, default=.5)
parser.add_argument('-c', type=float, default=2)
args = parser.parse_args()

from matplotlib import pyplot as plt
import numpy as np
from landau import denlan, diflan

X = np.arange(0,10,.001)

plt.figure()
plt.plot(X, [diflan(x, args.mu, args.c) for x in X], label="diflan")
plt.plot(X, [denlan(x, args.mu, args.c) for x in X], label="denlan")
plt.legend()
plt.show()

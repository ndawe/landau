#!/usr/bin/env python

from matplotlib import pyplot as plt
import numpy as np
from landau import denlan, diflan

X = np.arange(0,10,.001)

plt.figure()
plt.plot(X, [diflan(x,.5,2) for x in X], label="diflan")
plt.plot(X, [denlan(x,.5,2) for x in X], label="denlan")
plt.legend()
plt.show()

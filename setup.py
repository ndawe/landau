#!/usr/bin/env python

from glob import glob
from numpy.distutils.core import setup, Extension
import numpy


landau_ext = Extension('landau/_liblandau',
                       sources = glob('landau/src/*.c'),
                       include_dirs=[numpy.get_include()])

setup(name='landau',
      author='Noel Dawe',
      author_email='noel.dawe@cern.ch',
      packages=['landau'],
      ext_modules = [landau_ext]
     )

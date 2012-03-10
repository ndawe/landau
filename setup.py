#!/usr/bin/env python

from glob import glob
from distutils.core import setup, Extension

landau_ext = Extension('landau/_liblandau',
                       sources = ['landau/_liblandau.c'] + \
                                 glob('landau/src_c/*.c'))

setup(name='landau',
      author='Noel Dawe',
      author_email='noel.dawe@cern.ch',
      packages=['landau'],
      ext_modules = [landau_ext]
     )

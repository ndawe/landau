#!/usr/bin/env python

from glob import glob
import os

def configuration(parent_package='', top_path=None):

    from numpy.distutils.misc_util import Configuration
    config = Configuration('landau', parent_package,top_path)
    for path in glob('src/landau/*.F'):
        config.add_extension(os.path.splitext(os.path.basename(path))[0], [path])
    return config

if __name__ == "__main__":

    from numpy.distutils.core import setup
    setup(configuration=configuration)

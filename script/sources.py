#!/usr/bin/python3

from os import walk, path

for (dirpath, dirnames, filenames) in walk("src"):
    for name in filenames:
        print(path.join(dirpath, name))

#!/bin/bash
#### compile cpp programs
g++ -o try `root-config --cflags --libs --glibs` *.cxx


#!/bin/bash

JOBS=2

WORKDIR=`pwd`

# First - clean
rm -rf GeneratedFiles/ debug/

cd parsing
# First - clean
rm -f parser.flex.cpp parser.tab.cpp parser.tab.h
# Then build
flex -o parser.flex.cpp parser.l
bison -o parser.tab.cpp --defines=parser.tab.h parser.y
cd $WORKDIR

qmake step_visu_2_prj.pro
make -j$JOBS

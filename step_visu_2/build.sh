#!/bin/bash

JOBS=2

SRCDIR=`pwd`
BUILDDIRNAME=build

if [ ! -d "$SRCDIR/$BUILDDIRNAME" ]; then
	echo "Build directory not found."
	mkdir -v $SRCDIR/$BUILDDIRNAME
fi

# ---------------------------------------------------------
# First - clean

cd $SRCDIR/parsing
echo Going to `pwd`...
rm -fv parser.flex.cpp parser.tab.cpp parser.tab.h parser.output

cd $SRCDIR/$BUILDDIRNAME
echo Going to `pwd`...
unlink shaders
rm -rfv *

# Go back to the original directory
cd $SRCDIR
echo Going to `pwd`...

echo "Cleanup done."
echo

# ---------------------------------------------------------
# Then build

cd $SRCDIR/parsing
echo Going to `pwd`...
flex -v -o parser.flex.cpp parser.l
bison -v -o parser.tab.cpp --defines=parser.tab.h parser.y

cd $SRCDIR/$BUILDDIRNAME
echo Going to `pwd`...
qmake $SRCDIR/step_visu_2_prj.pro
make -j$JOBS
ln -s $SRCDIR/shaders

# Go back to the original directory
cd $SRCDIR
echo Going to `pwd`...

echo "Build done."


#!/bin/bash
set -e 
#set -x
cmake .
make VERBOSE=1
datafile=./Data/mr1.220405.wav
echo "Processing file."
if [[ "$1" = "x" ]]; then
    gdb --args ./songbird $datafile
else
    ./songbird $datafile
fi


#!/bin/bash

PWD=`cd $(dirname $0); pwd`
KPWD=$PWD

cd $KPWD/.libs/bin
LD_LIBRARY_PATH=$KPWD/.libs/lib valgrind --tool=memcheck --leak-check=full $KPWD/.libs/bin/test_d

#!/bin/bash

PWD=`cd $(dirname $0); pwd`
KPWD=$PWD

#Debug
cd $KPWD/.libs/bin
LD_LIBRARY_PATH=$KPWD/.libs/lib $KPWD/.libs/bin/test_d

echo "--------------------------------很长的分割线--------------------------------"

#Release
cd $KPWD/.libs/bin
LD_LIBRARY_PATH=$KPWD/.libs/lib valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all $KPWD/.libs/bin/test




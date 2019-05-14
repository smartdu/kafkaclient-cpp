#!/bin/bash

PWD=`cd $(dirname $0); pwd`
KPWD=$PWD

//rm -rf .libs .build
mkdir -p .libs .build
cd $PWD/.build

cmake -DCMAKE_BUILD_TYPE=Debug -DD_SUFFIX=_d -DPLATFORM=CentOS-x64 -DCMAKE_INSTALL_PREFIX=$KPWD/.libs/ $KPWD 
make && make install

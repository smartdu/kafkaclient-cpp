#!/bin/bash

mkdir -p .libs .build
cd .build
cmake -DCMAKE_BUILD_TYPE=Debug -DD_SUFFIX=_d -DPLATFORM=CentOS-x64 -DCMAKE_INSTALL_PREFIX=/svn/kafkaclient-cpp/.libs/ /svn/kafkaclient-cpp/
make && make install

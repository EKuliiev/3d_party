#!/bin/bash

readonly script_location="$( dirname $( realpath -s $0 ) )"

cd ${script_location}/boost_1_66_0
./bootstrap.sh --prefix=${script_location}/install/usr
b2_args+=" link=static cxxflags=\"-fPIC\" "
b2_args+=" --with-atomic --with-thread --with-date_time --with-chrono --with-system --with-filesystem --with-serialization --with-program_options "
./b2 $b2_args headers
./b2 $b2_args install
cd ..

#!/bin/bash

source /opt/qnx700/qnxsdp-env.sh

readonly script_location="$( dirname $( realpath -s $0 ) )"

cd ${script_location}/boost_1_66_0
./bootstrap.sh --prefix=${script_location}/install/usr
b2_args+=" link=static toolset=qcc address-model=32  cxxflags='-fPIC -Vgcc_ntoaarch64le' target-os=qnxnto "
b2_args+=" --with-atomic --with-thread --with-date_time --with-chrono --with-system --with-filesystem --with-serialization --with-program_options "
./b2 $b2_args headers
./b2 $b2_args install
cd ..

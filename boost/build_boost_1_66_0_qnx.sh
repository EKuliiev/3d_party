#!/bin/bash

source /opt/qnx700/qnxsdp-env.sh

set -e

readonly script_location="$( dirname $( realpath -s $0 ) )"

cd ${script_location}/boost_1_66_0
./bootstrap.sh --prefix=${script_location}/install/usr
b2_args+=" link=static toolset=qcc address-model=64 target-os=qnxnto cxxflags='-fPIC -Vgcc_ntoaarch64le' "
b2_args+=" --with-atomic --with-thread --with-date_time --with-chrono --with-system --with-filesystem --with-serialization --with-program_options "
command_to_perform="./b2 $b2_args headers"
echo " ---> Running '$command_to_perform'" 
eval $command_to_perform
command_to_perform="./b2 $b2_args install"
echo " ---> Running '$command_to_perform'" 
eval $command_to_perform

cd ..

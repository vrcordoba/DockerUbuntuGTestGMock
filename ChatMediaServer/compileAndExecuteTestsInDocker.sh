#!/bin/bash

function help {
   echo "Usage: $0 -c <CONTAINER_NAME> -t <TEST_SUITE>"
}

if [ $# -ne 4 ]
then
   echo "Wrong number of parameters"
   help
   exit 1
fi

CONTAINER_NAME=""
TEST_SUITE=""

while getopts "c:t:" opt
do
   case $opt in
      c)
         CONTAINER_NAME=$OPTARG
         ;;
      t)
         TEST_SUITE=$OPTARG
         ;;
      \?)
         help
         exit 1
         ;;
   esac
done

sudo docker run -v $PWD:/tmp/project -it $CONTAINER_NAME /bin/bash -c "cd /tmp/project && cmake . && make && ./$TEST_SUITE > results.txt && rm -rf CMakeCache.txt CMakeFiles cmake_install.cmake Makefile $TEST_SUITE && exit"

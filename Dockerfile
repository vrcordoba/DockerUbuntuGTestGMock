# Base image
FROM ubuntu:xenial

# Install CMake, compilers, GTest and GMock
RUN apt-get update && apt-get install -y cmake make gcc g++ libgtest-dev google-mock

# libgtest-dev and google-mock packages contain only source files
# Compile GTest libraries
WORKDIR /usr/src/gtest
RUN cmake .
RUN make
RUN mv libg* /usr/lib/

# Compile GMock libraries
WORKDIR /usr/src/gmock
RUN cmake .
RUN make
RUN mv libg* /usr/lib/

CMD echo "GTest and GMock correctly installed on Ubuntu Xenial docker"

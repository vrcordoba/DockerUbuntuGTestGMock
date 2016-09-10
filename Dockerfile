# Base image
FROM ubuntu:xenial

# Install CMake, compilers, wget and GTest
RUN apt-get update && apt-get install -y cmake libgtest-dev make gcc g++ wget
WORKDIR /usr/src/gtest
RUN cmake .
RUN make
RUN mv libg* /usr/lib/

# Download GMock sources
RUN mkdir /opt/googlemock
WORKDIR /opt/googlemock
RUN wget -O googlemock-1.7.0.tar.gz https://github.com/google/googlemock/archive/release-1.7.0.tar.gz
RUN tar xzf googlemock-1.7.0.tar.gz
RUN rm -rf googlemock-1.7.0.tar.gz

# Compile GMock
RUN mkdir gtest
RUN cp -r /usr/src/gtest/* gtest
WORKDIR googlemock-release-1.7.0
RUN cmake .
RUN make

# Install GMock
RUN mv libg* /usr/lib/
RUN cp -r include/gmock /usr/include/gmock

CMD echo "GTest and GMock correctly installed on Ubuntu Xenial docker"

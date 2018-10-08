#!/bin/sh
protoc pack.proto --cpp_out=./PKMSG
g++ main.cpp msg.h msg.cpp PKMSG/pack.pb.cc -o main `pkg-config --cflags --libs protobuf` -lpthread



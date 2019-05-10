CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: eulerGilbert eulerUniform topBottomGilbert topBottomUniform

eulerUniform: mainEulerUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerUniform.cc unionFind.cc unionFind.hh -o eulerUniform
eulerGilbert: mainEulerGilbert.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerGilbert.cc unionFind.cc unionFind.hh -o eulerGilbert
topBottomGilbert: topBottomGilbert.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomGilbert.cc unionFind.cc unionFind.hh -o topBottomGilbert
topBottomUniform: topBottomUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomUniform.cc unionFind.cc unionFind.hh -o topBottomUniform

clean:
	rm euler
	rm topBottom

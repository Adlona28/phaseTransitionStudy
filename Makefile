CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: connexErdos connexUniform eulerErdos eulerUniform topBottomErdos topBottomUniform

connexUniform: mainConnexUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexUniform.cc unionFind.cc unionFind.hh -o connexUniform
connexErdos: mainConnexErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexErdos.cc unionFind.cc unionFind.hh -o connexErdos
eulerUniform: mainEulerUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerUniform.cc unionFind.cc unionFind.hh -o eulerUniform
eulerErdos: mainEulerErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerErdos.cc unionFind.cc unionFind.hh -o eulerErdos
topBottomErdos: topBottomErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomErdos.cc unionFind.cc unionFind.hh -o topBottomErdos
topBottomUniform: topBottomUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomUniform.cc unionFind.cc unionFind.hh -o topBottomUniform

clean:
	rm euler
	rm topBottom

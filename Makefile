CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: eulerErdos eulerUniform topBottomErdos topBottomUniform topBottomNewman cyclesTest newmanCycles topBottomGraella

connexUniform: mainConnexUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexUniform.cc unionFind.cc unionFind.hh -o connexUniform
connexErdos: mainConnexErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexErdos.cc unionFind.cc unionFind.hh -o connexErdos
eulerUniform: mainEulerUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerUniform.cc unionFind.cc unionFind.hh -o eulerUniform.out
eulerErdos: mainEulerErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerErdos.cc unionFind.cc unionFind.hh -o eulerErdos.out
topBottomErdos: topBottomErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomErdos.cc unionFind.cc unionFind.hh -o topBottomErdos.out
topBottomUniform: topBottomUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomUniform.cc unionFind.cc unionFind.hh -o topBottomUniform.out
topBottomNewman: topBottomNewman.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomNewman.cc unionFind.cc unionFind.hh -o topBottomNewman.out
topBottomGraella: topBottomGraella.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomGraella.cc unionFind.cc unionFind.hh -o topBottomGraella.out
cyclesTest: cyclesTest.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) cyclesTest.cc unionFind.cc unionFind.hh -o cyclesTest.out
newmanCycles: newmanCycles.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) newmanCycles.cc unionFind.cc unionFind.hh -o newmanCycles.out

clean:
	rm euler
	rm topBottom

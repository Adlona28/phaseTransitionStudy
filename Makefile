CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: connexNewman connexErdos connexUniform eulerNewman eulerErdos eulerUniform topBottomErdos topBottomUniform topBottomNewman cyclesTest newmanCycles topBottomGraella

connexNewman: mainConnexNewman.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexNewman.cc unionFind.cc unionFind.hh -o connexNewman
connexUniform: mainConnexUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexUniform.cc unionFind.cc unionFind.hh -o connexUniform
connexErdos: mainConnexErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexErdos.cc unionFind.cc unionFind.hh -o connexErdos
eulerNewman: mainEulerNewman.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerNewman.cc unionFind.cc unionFind.hh -o eulerNewman
eulerUniform: mainEulerUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerUniform.cc unionFind.cc unionFind.hh -o eulerUniform
eulerErdos: mainEulerErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerErdos.cc unionFind.cc unionFind.hh -o eulerErdos
topBottomErdos: topBottomErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomErdos.cc unionFind.cc unionFind.hh -o topBottomErdos
topBottomUniform: topBottomUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomUniform.cc unionFind.cc unionFind.hh -o topBottomUniform
topBottomNewman: topBottomNewman.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomNewman.cc unionFind.cc unionFind.hh -o topBottomNewman
topBottomGraella: topBottomGraella.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomGraella.cc unionFind.cc unionFind.hh -o topBottomGraella
cyclesTest: cyclesTest.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) cyclesTest.cc unionFind.cc unionFind.hh -o cyclesTest
newmanCycles: newmanCycles.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) newmanCycles.cc unionFind.cc unionFind.hh -o newmanCycles

clean:
	rm connexNewman 
	rm connexErdos 
	rm connexUniform 
	rm eulerNewman 
	rm eulerErdos 
	rm eulerUniform 
	rm topBottomErdos 
	rm topBottomUniform 
	rm topBottomNewman 
	rm cyclesTest 
	rm newmanCycles 
	rm topBottomGraella

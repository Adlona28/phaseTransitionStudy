CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: graella connexErdos connexUniform eulerWatts eulerErdos eulerUniform topBottomErdos topBottomUniform topBottomWatts cyclesTest wattsCycles

graella: graella.cc
	$(CC) $(CFLAGS) graella.cc -o graella
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
topBottomWatts: topBottomWatts.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) topBottomWatts.cc unionFind.cc unionFind.hh -o topBottomWatts
cyclesTest: cyclesTest.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) cyclesTest.cc unionFind.cc unionFind.hh -o cyclesTest
wattsCycles: wattsCycles.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) wattsCycles.cc unionFind.cc unionFind.hh -o wattsCycles

clean:
	rm graella
	rm connexErdos 
	rm connexUniform 
	rm eulerErdos 
	rm eulerUniform 
	rm topBottomErdos 
	rm topBottomUniform 
	rm topBottomWatts 
	rm cyclesTest 
	rm wattsCycles 

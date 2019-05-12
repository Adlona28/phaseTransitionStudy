CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: connexWatts connexErdos connexUniform eulerWatts eulerErdos eulerUniform topBottomErdos topBottomUniform topBottomWatts cyclesTest wattsCycles

connexWatts: mainConnexWatts.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexWatts.cc unionFind.cc unionFind.hh -o connexWatts
connexUniform: mainConnexUniform.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexUniform.cc unionFind.cc unionFind.hh -o connexUniform
connexErdos: mainConnexErdos.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainConnexErdos.cc unionFind.cc unionFind.hh -o connexErdos
eulerWatts: mainEulerWatts.cc unionFind.cc unionFind.hh graphgen.cc properties.cc
	$(CC) $(CFLAGS) mainEulerWatts.cc unionFind.cc unionFind.hh -o eulerWatts
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
	rm connexWatts 
	rm connexErdos 
	rm connexUniform 
	rm eulerWatts 
	rm eulerErdos 
	rm eulerUniform 
	rm topBottomErdos 
	rm topBottomUniform 
	rm topBottomWatts 
	rm cyclesTest 
	rm wattsCycles 
	rm topBottomGraella

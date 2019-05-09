CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: euler topBottom

euler: mainEuler.cc unionFind.cc unionFind.hh
	$(CC) $(CFLAGS) mainEuler.cc unionFind.cc unionFind.hh -o euler
topBottom: mainTopBottom.cc unionFind.cc unionFind.hh
	$(CC) $(CFLAGS) mainTopBottom.cc unionFind.cc unionFind.hh -o topBottom

clean:
	rm euler
	rm topBottom

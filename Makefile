CC              = g++
CFLAGS          = -O3          -std=c++11 -Wall -Wno-unused-result -Wno-unused-variable

all: euler topBottomGilbert topBottomUniform

euler: mainEuler.cc unionFind.cc unionFind.hh
	$(CC) $(CFLAGS) mainEuler.cc unionFind.cc unionFind.hh -o euler
topBottomGilbert: topBottomGilbert.cc unionFind.cc unionFind.hh
	$(CC) $(CFLAGS) topBottomGilbert.cc unionFind.cc unionFind.hh -o topBottomGilbert
topBottomUniform: topBottomUniform.cc unionFind.cc unionFind.hh
	$(CC) $(CFLAGS) topBottomUniform.cc unionFind.cc unionFind.hh -o topBottomUniform

clean:
	rm euler
	rm topBottom

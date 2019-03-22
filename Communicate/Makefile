CXX = g++
FLG = -std=c++11 -Wall
INC = -I. -I/usr/include
LIB = -L/usr/lib
LIK = -lpthread
CLN = *.o *.so

test: test.o exchange.o
	$(CXX) $(FLG) $(INC) test.o exchange.o -o test $(LIB) $(LIK)

test.o: test.cpp exchange.h
	$(CXX) $(FLG) $(INC) -c test.cpp

exchange.o: exchange.cpp exchange.h
	$(CXX) $(FLG) $(INC) -c exchange.cpp

so: exchange.cpp exchange.h
	$(CXX) $(FLG) $(INC) exchange.cpp -fPIC -shared -o libexchange.so $(LIB) $(LIK)

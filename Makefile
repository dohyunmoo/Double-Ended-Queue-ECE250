all: dequeaslistdriver

dequeaslistdriver: dequeaslisttest.cpp Deque.hpp Linkedlist.hpp
	g++ -std=c++11 -o  dequeaslistdriver dequeaslisttest.cpp Deque.hpp Linkedlist.hpp

clean:
	rm *.o dequeaslistdriver
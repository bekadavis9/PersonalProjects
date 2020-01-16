all: main clean

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o

main.o: main.cpp card.h deck.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *o main
	echo clean

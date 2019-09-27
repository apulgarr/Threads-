all: miHilo miHilo2

miHilo: miHilo.o
	$(CXX) -o $@ $^ -pthread 

miHilo2: miHilo2.o
	$(CXX) -o $@ $^ -pthread

clean:
	rm -f miHilo
	rm -f miHilo2
	rm -f *.o

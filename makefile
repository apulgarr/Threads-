all: miHilo miHilo2 miHilo3 miHilo4

miHilo: miHilo.o
	$(CXX) -o $@ $^ -pthread 

miHilo2: miHilo2.o
	$(CXX) -o $@ $^ -pthread

miHilo3: miHilo3.o
	$(CXX) -o $@ $^ -pthread

miHilo4: miHilo4.o
	$(CXX) -o $@ $^ -pthread

clean:
	rm -f miHilo
	rm -f miHilo2
	rm -f miHilo3
	rm -r miHilo4
	rm -f *.o

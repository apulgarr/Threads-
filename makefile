all: miHilo

miHilo: miHilo.o
	$(CXX) -o $@ $^ -pthread

clean:
	rm -f miHilo
	rm -f *.o

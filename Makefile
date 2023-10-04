all:
	g++ -std=c++11 main.cpp -o main.o

clean:
	rm -rf *.o
run:
	./main.o
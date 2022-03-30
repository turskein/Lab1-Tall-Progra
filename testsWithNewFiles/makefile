test_Heap_1: Node.o Heap.o test_Heap_1.cpp
	g++ Node.o Heap.o test_Heap_1.cpp -o test_Heap_1
	
Heap.o: Node.h Heap.cpp Heap.h
	g++ -c Heap.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o test_Heap_1

run_test: test_Heap_1
	./test_Heap_1

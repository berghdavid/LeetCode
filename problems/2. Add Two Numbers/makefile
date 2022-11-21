default: solve

solve.o: solve.c $(HEADERS)
	gcc -c solve.c -o solve.o

solve: solve.o
	gcc solve.o -o solve

clean:
	-rm -f solve.o
	-rm -f solve

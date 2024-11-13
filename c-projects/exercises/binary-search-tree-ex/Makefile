gcc: a.exe

tree.o: tree.c tree.h
	gcc -c tree.c tree.h -o tree.o

a.out: main.c tree.o
	gcc main.c tree.o -o a.exe

clean:
	del *.exe *.o
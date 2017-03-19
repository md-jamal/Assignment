.PHONY : clean

calculator : calculator.o add.o sub.o mul.o div.o
	gcc -o calculator calculator.o add.o sub.o mul.o div.o

calculator.o : calculator.c header.h
	gcc -c calculator.c header.h

add.o : add.c header.h
	gcc -c add.c header.h

sub.o : sub.c header.h
	gcc -c sub.c header.h

mul.o : mul.c header.h
	gcc -c mul.c header.h

div.o : div.c header.h
	gcc -c div.c header.h

clean :
	rm calculator *.o

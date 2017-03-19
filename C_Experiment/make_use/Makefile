my_prog : 1.o 2.o main.o
	gcc -o app 1.o 2.o main.o

1.o:
	gcc -c 1.c
2.o:
	gcc -c 2.c
main.o:
	gcc -c main.c

clean:
	find . -param+100 -type f -delete


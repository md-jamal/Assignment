.PHONY : clean
CC = gcc


calculator : calculator.o add.o sub.o mul.o div.o
	$(CC) -o $@ $^ 

#Pattern Rule
%.o : %.c header.h
	$(CC) -c $< header.h

clean :
	rm calculator *.o

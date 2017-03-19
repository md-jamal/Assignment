.PHONY : clean
CC = gcc

VPATH = source1 source2 source3 source4 header object
					# search all type files in above listed directories
SOURCE := $(shell ls ./source1/) 	# Immediate Set
SOURCE += $(shell ls ./source2/) 	# Append
SOURCE += $(shell ls ./source3/) 
SOURCE += $(shell ls ./source4/)

OBJECT := $(SOURCE:%.c=%.o) 	# Pattern Substitution

HDR := ./header 

calculator : $(OBJECT) 
	$(CC) -o $@ $^
	mv *.o ./object/

%.o : %.c header.h 
	$(CC) -c $^  -I $(HDR)

clean :
	rm ./object/*.o 

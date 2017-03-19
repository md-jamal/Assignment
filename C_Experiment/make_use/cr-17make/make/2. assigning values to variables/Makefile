#Lazy set
LAZY = This is lazy set

#immediate set
IMMEDIATE := $(LAZY) used in immediate set		#check for both set
#IMMEDIATE = i am at the

#Set if absent
#IFSET = already defined
IFSET ?= not defined earlier, so defined now		#set if absent

#Append set
APPEND = Global		#append
APPEND += Edge		#append
APPEND += Software
APPEND += Limited

all :
	@echo "LAZY : "$(LAZY)
	@echo "IMMEDIATE : "$(IMMEDIATE)
	@echo "IFSET : "$(IFSET)
	@echo "APPEND : "$(APPEND)


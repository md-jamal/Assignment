obj-m:=kmod3.o

SYMBOLA = /home/pritam/Training/LINUX/EXP/module1/printa/Module.symvers
SYMBOLB = /home/pritam/Training/LINUX/EXP/module2/printb/Module.symvers

KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
KBUILD_EXTRA_SYMBOLS = $(SYMBOLA) $(SYMBOLB)
all:
	$(MAKE) -C $(KDIR)/ $(KBUILD_EXTRA_SYMBOL) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod
	

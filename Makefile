obj-m = echo.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

Clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

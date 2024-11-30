TARGET_MODULE:=usb_encrypt

USER_APP:=user_app

# If we running by kernel building system
ifneq ($(KERNELRELEASE),)
	$(TARGET_MODULE)-objs := usb_encrypt.o
	obj-m := $(TARGET_MODULE).o

# If we are running without kernel build system
else
	BUILDSYSTEM_DIR:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)


all : kernel user_app

kernel:
# run kernel build system to make module
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) modules

user_app:
# Build the user application
	gcc -o $(USER_APP) user_app.c

clean:
# run kernel build system to cleanup in current directory
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) clean
# Clean user application
	rm -f $(USER_APP)

load:
	@echo "Loading Module..."
	insmod $(TARGET_MODULE).ko
	dmesg | tail -n 10

unload:
	@echo "Unloading Module..."
	rmmod ./$(TARGET_MODULE).ko
	dmesg | tail -n 10

endif



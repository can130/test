#Desing by chuncanL for spv5210
#define var

TARGET := led.bin
BUILD  := led

ENV    ?= SD
SDTOOLS:= ./mk210

COBJS += Start.o
COBJS += main.o
COBJS +=led.o

#编译器  链接器
CROSS_COMPILE  := arm-linux-
CC     :=  $(CROSS_COMPILE)gcc   
LD     :=  $(CROSS_COMPILE)ld
OBJCOPY:=  $(CROSS_COMPILE)objcopy

CFLAGS += -Wall    #编译选项
CFLAGS += -I./inc  #头文件地址

LDFLAGS += -Tmap.lds  #头文件地址

ifeq ($(ENV),SD)
LDFLAGS +=  -Ttext=0x0 #链接选项
else
LDFLAGS +=  -Ttext=0x20000000
endif

#way
all:$(TARGET)
ifeq ($(ENV),RAM)
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary  $^ $@
else	
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary  $^ $@.TMP
	$(SDTOOLS) $@.TMP $@
endif

	cp $@ ../binary -f

$(BUILD):$(COBJS)
	$(LD) $(LDFLAGS) -o $@ $^
	
%.o:%.c
	$(CC)  $(CFLAGS)  -c -o  $@ $^
%.o:%.S
	$(CC)  $(CFLAGS)  -c -o  $@ $^
	
clean:
	rm -f $(TARGET) $(BUILD) *.o *.TMP
	
COMMON_OBJECTS = 
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: main.elf

main.elf: ${COMMON_OBJECTS} main.o buzzer.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: main.c buzzer.h sound.h
	${CC} ${CFLAGS} -c -o $@ $<

buzzer.o: buzzer.c buzzer.h
	${CC} ${CFLAGS} -c -o $@ $<

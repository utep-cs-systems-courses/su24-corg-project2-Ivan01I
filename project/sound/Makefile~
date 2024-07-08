COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: make_sound.elf

make_sound.elf: ${COMMON_OBJECTS} make_sound.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: make_sound.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

make_sound.o: make_sound.c make_sound.h
	${CC} ${CFLAGS} -c -o $@ $<

main.o: main.c make_sound.h
	${CC} ${CFLAGS} -c -o $@ $<

%.o: %.c
	${CC} ${CFLAGS} -c $<

.PHONY: clean

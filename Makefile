C=gcc
CFLAGS= -O3 -Wall -g
LIBS= -lm
AR=ar

ALLBIN=getbno080

all: ${ALLBIN}

clean:
	rm -f *.o ${ALLBIN}

getbno080: i2c_bno080.o getbno080.o defs.o
	$(CC) i2c_bno080.o getbno080.o defs.o -o getbno080 ${LIBS}


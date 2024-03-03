
TESTDIR = ./test
LIBDIR = ./lib

TEST_EXEC := ${TESTDIR}/test.out

TEST_INCLUDE = -I${LIBDIR}

CFALGS += ${TEST_INCLUDE}
CFALGS += -Wall 
CFALGS += -g

CC := gcc 


socketLib : ${LIBDIR}/libtsocket.so

.PHONY:socketLib


all:default

default:
	cmake -S. -Bbuild 

clean:
	if [ -d build ]; then rm -r build; fi
	if [ -f ${TEST_EXEC} ]; then rm ${TEST_EXEC}; fi
	rm -f *.dat

test:
	@echo "TEST_EXEC = ${TEST_EXEC}"
	@echo "CC = ${CC}"


testing: ${TEST_EXEC}
	$(CC) $(CFALGS) -o ${TEST_EXEC} ${TESTDIR}/main.c ${LIBDIR}/dnslib.c 

run:testing
	${TEST_EXEC}

retry:clean run
	make clean
	make run


${LIBDIR}/libtsocket.so:${LIBDIR}/t_socket.c ${LIBDIR}/include/t_socket.h
	gcc -c -fPIC -c ${LIBDIR}/t_socket.c -I${LIBDIR}/include  -o ${LIBDIR}/tsocket.o
	gcc -shared -o $@ ${LIBDIR}/tsocket.o
	rm ${LIBDIR}/tsocket.o
	


${TEST_EXEC}:

.PHONY: test default clean retry
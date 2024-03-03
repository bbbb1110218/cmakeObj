
    
CURRENT_DIR = ./
INCLUDE_DIR = ../include 
LIB_DIR = ../lib2
DIR_BIN = ../objs

DEFINES = -DNEED_DEBUG=0

FLAGS = -g 

SRC = $(CURRENT_DIR)/test.c \
    $(LIB_DIR)/QDNS.c  \
    $(LIB_DIR)/Qsocket.c 

OBJ_C =$(wildcard ${CURRENT_DIR}/*.c ${LIB_DIR}/*.c)

OBJ_O = $(patsubst %.c,${DIR_BIN}/%.o,$(notdir ${OBJ_C}))

test.out: $(OBJ_O)
	gcc -o $@ $^ -I$(INCLUDE_DIR) $(DEFINES) $(FLAGS)

${DIR_BIN}/%.o: ${CURRENT_DIR}/%.c
	gcc -c $< -o $@ -I$(INCLUDE_DIR) $(DEFINES) $(FLAGS)

${DIR_BIN}/%.o: ${LIB_DIR}/%.c
	gcc -c $< -o $@ -I$(INCLUDE_DIR) $(DEFINES) $(FLAGS)

.PHONY: clean
clean:
	rm -f $(DIR_BIN)/*.o test.out

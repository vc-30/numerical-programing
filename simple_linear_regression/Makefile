EXE=linear_regression_test

CC=gcc

SRC_DIR=src
OBJ_DIR=obj

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS += -Iinclude
CFLAGS += -std=c99 -Wall
LDFLAGS += -Llib
LDLIBS += -lm

.PHONY:
	all clean

 
all:$(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $(EXE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
       
clean:
	$(RM) $(OBJ) $(EXE)	

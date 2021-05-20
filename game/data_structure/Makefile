OBJ = my_list.o my_stack.o test.o my_vector.o
INC_STACK = my_stack.h _my_stack.h
INC_LIST = my_list.h _my_list.h _my_iterator.h \
	_my_list_iterator.h
DIR_CUR = /home/yang/code/my/my_data_structure
DIR_STACK = $(DIR_CUR)/stack
DIR_LIST = $(DIR_CUR)/list
DIR_VECTOR = $(DIR_CUR)/vector

CC = gcc
CFLAGS = -g -Wall -fms-extensions -I/$(DIR_LIST) -I/$(DIR_STACK) -I/$(DIR_VECTOR)

TARGET = test

VPATH = list:stack:vector


$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $@
	 
%.o :  %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY : clean
clean :
	rm -f $(OBJ) 

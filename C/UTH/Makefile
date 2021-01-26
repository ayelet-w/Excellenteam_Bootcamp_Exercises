TARGET=main
# all .c files in this directory are my sources
SOURCES=$(wildcard *.c)

OBJS=$(SOURCES:.c=.o)

CC=gcc
CFLAGS = -c -pedantic -Wall -Werror -Wconversion -ansi -g
CXXFLAGS = $(CFLAGS)
LDFLAGS=-g

.PHONY: clean run gdb

$(TARGET): $(OBJS)

include .depends

clean:
	rm -f $(OBJS) depends $(TARGET)
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)



.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends



TARGET=main
# all .c files in this directory are my sources
SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)


CC=g++
CFLAGS = -c -Wall -pedantic -Wconversion -ansi -g
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


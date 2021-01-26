TARGET=main
# all .cpp files in this directory are my sources
SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

CC=g++
CFLAGS = -c -pedantic -Wall -Werror -Wconversion  -g
CXXFLAGS = $(CFLAGS)
LDFLAGS=-g
LDLIBS=-lgtest -lgtest_main -lpthread

.PHONY: clean run gdb 

$(TARGET): $(OBJS)

include .depends

clean:
	rm -f $(OBJS) .depends $(TARGET)
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)
	


.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends





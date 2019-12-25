CC=gcc

INC_FLAGS= ../include

CFLAGS= -c -pedantic -g -I$(INC_FLAGS) -D _DEBUG
CXXFLAGS=$(CFLAGS)

TARGET = cpp2c_polymorphism_defs
SOURCES=$(wildcard *.c)
OBJS = $(SOURCES:.c=.o)


$(TARGET): $(OBJS)

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET) leak


.PHONY: clean run gdb

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends



clean:
	rm -f $(OBJS) $(TARGET)

leak: $(TARGET)
	 valgrind --leak-check=full ./$(TARGET)

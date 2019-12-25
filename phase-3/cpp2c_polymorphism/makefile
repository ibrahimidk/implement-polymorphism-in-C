CC=g++

INC_FLAGS= ../include

CFLAGS= -c -pedantic -g -I$(INC_FLAGS)
CXXFLAGS=$(CFLAGS)

TARGET = cpp2c_polymorphism_defs
SOURCES=$(wildcard *.cpp)
OBJS = $(SOURCES:.cpp=.o)


$(TARGET): $(OBJS)

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)


.PHONY: clean run gdb leak

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends



clean:
	rm -f $(OBJS) $(TARGET)
	
leak: $(TARGET)
	 valgrind --leak-check=full ./$(TARGET)

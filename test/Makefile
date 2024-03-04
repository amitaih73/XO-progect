cxx = g++
cc = $(cxx)

CXXFLAGS  = -pedantic -Wall -Werror -Wextra
CXXFLAGS += -g3
CXXFLAGS += -std=c++17

CPPFLAGS = -DDEBUG

CPPFLAGS = -I$(INCLUDES_DIR)

INCLUDES_DIR = ../inc
SOURCES_DIR = ../src


LDLIBS = -lstdc++


TARGET =test

OBJECTS = $(SOURCES_DIR)/ui.o $(SOURCES_DIR)/xo.o $(SOURCES_DIR)/bord.o test.o

all: $(TARGET)

vala: $(TARGET)
	@valgrind --leak-check=yes --track-origins=yes ./$(TARGET) 2> val.txt


$(TARGET): $(OBJECTS)

check: $(TARGET)
	./$(TARGET)

recheck: clean check

clean:
	$(RM)  $(TARGET) $(OBJECTS) val.txt


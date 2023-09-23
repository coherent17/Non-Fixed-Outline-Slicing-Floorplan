# ompiler & Linker settings
CC = g++
CFLAGS = -g -Wall -O3 -I./inc

# Valgrind for memory issue
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 

# Source files and object files
SRCDIR = src
OBJDIR = obj
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Name of the executable
TARGET = main

all: $(TARGET)

$(OBJDIR):
	mkdir $(OBJDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) main.cpp $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

check:
	$(CHECKCC) $(CHECKFLAGS)

do1:
	./$(TARGET) testcase/t10.txt

do2:
	./$(TARGET) testcase/t20.txt

do3:
	./$(TARGET) testcase/t30.txt

do4:
	./$(TARGET) testcase/t200.txt

do5:
	./$(TARGET) testcase/t300.txt

clean:
	rm -rf $(OBJDIR) $(TARGET) testcase/*.out
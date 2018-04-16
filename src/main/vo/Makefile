CC := g++
RM := rm -f
SRCDIR := src
BUILDDIR := build
EXECDIR := bin
TARGET := ordenacion 

OBJS := DNI/DNI.o main.o

CFLAGS :=	-g -std=c++11	# Compiler flags
LIB := # Libraries required i.e. -pthread

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(EXECDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

study: bin/main
	./bin/main

doc: Doxyfile
	doxygen Doxyfile

clean:
	$(RM) $(BUILDDIR) $(TARGET)

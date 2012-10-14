# Basic variables
CC=colorgcc
CXXFLAGS=-g -O2 -Wall

# Working folders
SRCDIR=../src
HEADERDIR=../include
LIBDIR=../../v8/lib

#Files
OBJS=v8test.o

# Link libraries
LIBS=-lv8_base -lv8_nosnapshot -lpreparser_lib -lpthread

# Target
TARGET=../bin/basev8test

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJS) -L$(LIBDIR) $(LIBS)

%.o: $(SRCDIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $<

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

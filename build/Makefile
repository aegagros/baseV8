# Basic variables
CC=g++
CXXFLAGS=-g -O2 -Wall

# Working folders
SRCDIR=../src
HEADERDIR=../include

#Files
OBJS=v8test.o
HEADERS=baseV8.h Class.h Common.h Constructor.h Def.h Exception.h Function.h Method.h Property.h Table.h Type.h

# Link libraries
LIBS=-lv8 -lv8preparser -lpthread

# Target
TARGET=../bin/basev8test

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: $(SRCDIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $<

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

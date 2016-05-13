#Make file for the given program
CC=g++
CPPFLAGS=-g -Wall -std=c++14
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))
OBJ_DIR=../obj/
OBJS=$(OBJ_DIR)*.o
LDFLAGS=
INC=-I. -I../inc

RM=rm -rvf
TARGET=logger

.PHONY:all

%.o: %.cpp
	$(CC) -c $(CPPFLAGS) $(INC) $< -o $(OBJ_DIR)$@

all:$(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJS) $(INC) $(LDFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
	find . -name "*.o" -exec $(RM) {} \;

SOURCES=$(wildcard *.cpp)
EXECS=$(patsubst %.cpp,%,$(SOURCES))
CC = g++
CCFLAGS = -std=c++17 -pedantic -Wall -g

all: $(EXECS)

%: %.cpp
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm -f $(EXECS) a.out

.PHONY: all clean
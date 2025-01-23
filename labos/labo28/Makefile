SOURCES=main.cpp is_prime.cpp rsa_keygen.cpp modular_math.cpp
EXECS=rsa
CC = g++
CCFLAGS = -std=c++17 -pedantic -Wall -g

all: $(EXECS)

rsa: $(SOURCES)
	$(CC) $(CCFLAGS) $(SOURCES) -o rsa.out

clean:
	rm -f $(EXECS) rsa.out

.PHONY: all clean
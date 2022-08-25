CC=g++
CFLAGS=-c -Wall
LDFLAGS=
HEADERS=testSolveSquare.h funcSolveSquare.h
SOURCES=SolveSquare.cpp testSolveSquare.cpp funcSolveSquare.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=solver

all: $(SOURCES) $(HEADERS) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
SOURCES = fraction.h fraction.cpp fraction_exception.h test_fraction.cpp
BINFILE = test_fraction 
CC = g++
CPPFLAGS = -std=c++0x
CXXFLAGS = -Wall
LDFLAGS = 

all: $(BINFILE)

$(BINFILE): $(SOURCES)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(SOURCES) -o $(BINFILE)

clean:
	rm $(BINFILE)

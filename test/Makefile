#Makefile for gtest
PRG=testBlast

CFLAGS=-O3 -I./ -I../
LDFLAGS=
LIBS=-lgtest -lgtest_main -lpthread

default: all

all: $(PRG)

HEADERS = \
	test_blast.h \
	test_taukita.h \
	$(NULL)

SOURCES = \
	test_main.cpp \
	test_blast.cpp \
	test_taukita.cpp \
	$(NULL)

OBJECTS = \
	test_main.o \
	test_blast.o \
	test_taukita.o \
	$(NULL)

OBJECTS_MAIN = \
	../Bomb.o \
	../Blast.o \
	../TauKita.o \
	$(NULL)

$(PRG): $(OBJECTS) $(OBJECTS_MAIN)
	$(CXX) -o $@ $(OBJECTS) $(OBJECTS_MAIN) $(LDFLAGS) $(LIBS)

.cpp.o: Makefile $(HEADERS)
	$(CXX) -c $(CFLAGS) -o $@ $<

*.o: $(SOURCES) $(HEADERS)

clean:
	rm -f $(PRG) $(OBJECTS)

distclean: clean
	rm -f *~

.PHONY: all clean distclean


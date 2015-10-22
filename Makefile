
PRG=blast

CFLAGS=-O3
LDFLAGS=
LIBS=

default: all

all: $(PRG)

HEADERS = \
	Bomb.h \
	Blast.h \
	TauKita.h \
	main.h \
	$(NULL)

SOURCES = \
	Bomb.cpp \
	Blast.cpp \
	TauKita.cpp \
	main.cpp \
	$(NULL)

OBJECTS = \
	Bomb.o \
	Blast.o \
	TauKita.o \
	main.o \
	$(NULL)

$(PRG): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS) $(LIBS)

.cpp.o: Makefile $(HEADERS)
	$(CXX) -c $(CFLAGS) -o $@ $<

*.o: $(SOURCES) $(HEADERS)

clean:
	rm -f $(PRG) $(OBJECTS)

distclean: clean
	rm -f *~

.PHONY: all clean distclean


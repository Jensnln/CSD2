
# Makefile voor HelloGoodbye
#
# Marc_G 2012

CC = g++
CFLAGS = -Wall
PROG = opdracht_1.jens
SRC = main.cpp instruments/instrument.cpp
OBJS = main.o instrument.o

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(PROG) $(OBJS)

depend:
	makedepend $(SRC)

# Makefile voor HelloGoodbye
#
# Marc_G 2012

CXX = g++
CXXFLAGS = -Wall
PROG = zz.jens
SRC = main.cpp instrument.cpp stringed.cpp woodwinds.cpp
OBJS = main.o instrument.o stringed.o woodwinds.o

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	/bin/rm -f $(PROG) $(OBJS)

depend:
	makedepend $(SRC)
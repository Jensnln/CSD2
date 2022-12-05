CXX=g++
CXXFLAGS=-Wall -std=c++1z
LDFLAGS=
SOURCE= main.o writeToFile.o sine.o
TARGET= zz.jens

$(TARGET): $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f $(TARGET) *.o *.csv

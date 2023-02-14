CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z -g
LDFLAGS= -ljack
SOURCE= FFT.o
TARGET= FFT

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o *.csv



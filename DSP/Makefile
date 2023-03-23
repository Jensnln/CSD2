CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z -g
SOURCE= FFT.o writeToFile.o
TARGET= FFT

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o *.csv



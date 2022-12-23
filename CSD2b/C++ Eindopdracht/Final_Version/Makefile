CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z -g
LDFLAGS= -ljack
SOURCE=main.o sine.o square.o saw.o oscillator.o synth.o melody.o addSynth.o sawSynth.o pwmSynth.o UI.o
TARGET=Synth

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o *.csv


CXX = g++
OPTIONS = -Wall
PROGRAM = main.exe

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Card.cpp Deck.cpp Hand.cpp summary.cpp
	$(CXX) $(OPTIONS) main.cpp Card.cpp Deck.cpp Hand.cpp summary.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

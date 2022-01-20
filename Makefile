CC=g++
CCFLAGS= -Wall #-Werror -std=c++11 -g
LIBFLAGS= -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ $(LIBFLAGS) -o $@

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) *.*~

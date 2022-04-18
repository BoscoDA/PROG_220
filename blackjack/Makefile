CC = g++
CFLAGS = -Wall -Wextra -Werror -O2 -std=c++11
OBJ = card.o deck.o player.o game.o
DEPS = card.h deck.h player.h game.h
MAIN = main.o

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

app: ${MAIN} ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}

.PHONY: clean
clean:
	rm *.o app *.out
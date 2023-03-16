dirs:
	mkdir bin

snake:
	cc src/linux-snake.c -I"include" -lSDL2 -o bin/linuxsnake

all: dirs snake

clean:
	rm -rf bin

debug:
	rm -rf bin && mkdir bin && cc src/linux-snake.c -I"include" -lSDL2 -o bin/linuxsnake && ./bin/linuxsnake
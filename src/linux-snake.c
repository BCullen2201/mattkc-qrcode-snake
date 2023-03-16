#include <stdio.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH        640
#define WINDOW_HEIGHT       480
#define TILE_SIZE           40
#define HORIZONTAL_TILES    WINDOW_HEIGHT / TILE_SIZE
#define VERTICAL_TILES      WINDOW_HEIGHT / TILE_SIZE
#define MAX_TILE_COUNT      HORIZONTAL_TILES * VERTICAL_TILES
#define START_X             HORIZONTAL_TILES / 2
#define START_Y             VERTICAL_TILES / 2
#define SNAKE_PADDING       TILE_SIZE / 4
#define SNAKE_SIZE          TILE_SIZE - SNAKE_PADDING - SNAKE_PADDING
#define FOOD_PADDING        TILE_SIZE / 8
#define FOOD_SIZE           TILE_SIZE - FOOD_PADDING - FOOD_PADDING
#define MAX_DIR_QUEUE       8

struct Position {
    int x, y;
};

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "Snake",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_ALLOW_HIGHDPI
    );

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL window failed to start: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Event event;
    int running = 1;

    while(running) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
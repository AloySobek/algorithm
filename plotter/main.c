#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#define SCREEN_HEIGHT 1280
#define SCREEN_WIDTH 720

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

App *init_app() {
    App *app = (App *)malloc(sizeof(App));

    int renderer_flags, window_flags;

    renderer_flags = SDL_RENDERER_ACCELERATED;

    window_flags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());

        exit(1);
    }

    app->window = SDL_CreateWindow("Plotter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

    if (!app->window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());

        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app->renderer = SDL_CreateRenderer(app->window, -1, renderer_flags);

    if (!app->renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());

        exit(1);
    }

    return app;
}

void destroy_app(App *app) {}

int main() {
    App *app = init_app();

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);

            break;
        default:
            break;
        }
    }

    destroy_app(app);

    return 0;
}

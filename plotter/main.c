#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

enum image_index {
    PRESS,
    RIGHT,
    LEFT,
    UP,
    DOWN,

    MAX
};

typedef struct {
    SDL_Window *window;
    // SDL_Renderer *renderer;
    SDL_Surface *surface;
} App;

App *init_app() {
    App *app = (App *)malloc(sizeof(App));

    int renderer_flags, window_flags;

    renderer_flags = SDL_RENDERER_ACCELERATED;

    window_flags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());

        return NULL;
    }

    app->window = SDL_CreateWindow("Plotter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

    if (!app->window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());

        return NULL;
    }

    int img_flags = IMG_INIT_PNG;

    if ((IMG_Init(img_flags) & img_flags) != img_flags) {
        printf("SDL_image could not be initialized! SDL_image Error: %s\n", IMG_GetError());

        SDL_DestroyWindow(app->window);

        return NULL;
    }

    app->surface = SDL_GetWindowSurface(app->window);

    // SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    // app->renderer = SDL_CreateRenderer(app->window, -1, renderer_flags);

    // if (!app->renderer) {
    //     printf("Failed to create renderer: %s\n", SDL_GetError());

    //     return NULL;
    // }

    return app;
}

SDL_Surface *load_and_optimize_image(App *app, const char *file) {
    SDL_Surface *surface = IMG_Load(file);
    SDL_Surface *optimized = NULL;

    if (surface == NULL) {
        printf("Unalbe to load image %s! SDL Error: %s\n", file, SDL_GetError());

        return NULL;
    }

    optimized = SDL_ConvertSurface(surface, app->surface->format, 0);

    if (optimized == NULL) {
        printf("Unable to optimize image %s! SDL ERror: %s\n", file, SDL_GetError());

        SDL_FreeSurface(surface);

        return NULL;
    }

    return optimized;
}

void destroy_app(App *app) {
    // SDL_DestroyRenderer(app->renderer);

    SDL_DestroyWindow(app->window);

    SDL_Quit();

    free(app);
}

int main() {
    App *app = init_app();

    if (app == NULL) {
        return -1;
    }

    SDL_Surface *image = load_and_optimize_image(app, "loaded.png");

    if (image == NULL) {
        return -1;
    }

    SDL_Event e;

    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        SDL_Rect rect;

        rect.x = 0;
        rect.y = 0;

        rect.w = SCREEN_WIDTH;
        rect.h = SCREEN_HEIGHT;

        SDL_BlitScaled(image, NULL, app->surface, &rect);

        SDL_UpdateWindowSurface(app->window);
    }

    SDL_FreeSurface(image);

    destroy_app(app);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

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

    app->surface = SDL_GetWindowSurface(app->window);

    // SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    // app->renderer = SDL_CreateRenderer(app->window, -1, renderer_flags);

    // if (!app->renderer) {
    //     printf("Failed to create renderer: %s\n", SDL_GetError());

    //     return NULL;
    // }

    return app;
}

enum image_index {
    PRESS,
    RIGHT,
    LEFT,
    UP,
    DOWN,

    MAX
};

SDL_Surface **load_image(App *app) {
    SDL_Surface **images = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * MAX);

    char *names[MAX] = {"press.bmp", "right.bmp", "left.bmp", "up.bmp", "down.bmp"};

    for (int i = 0; i < MAX; ++i) {
        *(images + i) = SDL_LoadBMP(names[i]);

        if (*(images + i) == NULL) {
            printf("Unable to load image %s! SDL Error: %s\n", names[i], SDL_GetError());

            free(images);

            return NULL;
        }
    }

    return images;
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

    SDL_Surface **images = load_image(app);

    if (images == NULL) {
        return -1;
    }

    SDL_Event e;

    int quit = 0;

    SDL_Surface *current_surface = images[PRESS];

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_RIGHT: {
                    current_surface = images[RIGHT];
                    break;
                }
                case SDLK_LEFT: {
                    current_surface = images[LEFT];
                    break;
                }
                case SDLK_UP: {
                    current_surface = images[UP];
                    break;
                }
                case SDLK_DOWN: {
                    current_surface = images[DOWN];
                    break;
                }
                default: {
                    current_surface = images[PRESS];
                    break;
                }
                }
            } else if (e.type == SDL_KEYUP) {
                current_surface = images[PRESS];
            }
        }

        SDL_BlitSurface(current_surface, NULL, app->surface, NULL);

        SDL_UpdateWindowSurface(app->window);
    }

    for (int i = 0; i < MAX; ++i) {
        SDL_FreeSurface(*(images + i));
    }

    free(images);

    destroy_app(app);

    return 0;
}

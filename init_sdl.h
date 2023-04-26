#ifndef GLOBAL_InitSDL
#define GLOBAL_InitSDL

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "env.h"
#include "src/list_view.h"

class INIT_SDL3
{
public:
    bool init();

    void close();

    void start();

    SDL_Window *gWindow = NULL;

    SDL_Renderer *gRenderer = NULL;

    ListView *listView;
};

bool INIT_SDL3::init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        this->gWindow = SDL_CreateWindow("Sliding Puzzle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (this->gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (this->gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

void INIT_SDL3::close()
{
    SDL_DestroyRenderer(this->gRenderer);
    SDL_DestroyWindow(this->gWindow);
    this->gWindow = NULL;
    this->gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
}

void INIT_SDL3::start()
{
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    if (!this->init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        SDL_Event e;

        this->listView = new ListView(this->gRenderer);
        bool quit = false;
        while (!quit)
        {
            frameStart = SDL_GetTicks();

            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                this->listView->event(&e);
            }

            SDL_SetRenderDrawColor(this->gRenderer, 26, 61, 60, 255);
            SDL_RenderClear(this->gRenderer);
            this->listView->renderImage();

            SDL_RenderPresent(this->gRenderer);

            frameTime = SDL_GetTicks() - frameStart;

            if (frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
        }
    }

    this->listView->closeImage();
    this->close();
}

#endif
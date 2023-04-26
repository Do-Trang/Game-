#ifndef GLOBAL_View
#define GLOBAL_View

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include "../../env.h"

class View
{
public:
    void initView(SDL_Renderer *gRenderer, std::string url, int x, int y, int w, int h);
    SDL_Renderer *gRenderer = NULL;

    SDL_Texture *gTexture = NULL;
    SDL_Texture *loadTexture(std::string url);
    Mix_Music *gMusic = NULL;
    int mouse_x, mouse_y;

    void closeImage();
    int x;
    int y;
    int w;
    int h;

private:
};
SDL_Texture *View::loadTexture(std::string url)
{
    SDL_Surface *loadedSurface = IMG_Load(url.c_str());
    SDL_Texture *gTexture;
    if (loadedSurface == NULL)
    {
        printf("Unable to load image");
    }
    else
    {
        gTexture = SDL_CreateTextureFromSurface(this->gRenderer, loadedSurface);

        if (gTexture == NULL)
        {
            printf("Unable to create texture");
        }

        SDL_FreeSurface(loadedSurface);
    }

    if (gTexture == NULL)
    {
        printf("Failed to load texture image!\n");
    }
    return gTexture;
}
void View::initView(SDL_Renderer *gRenderer, std::string url, int x, int y, int w, int h)
{
    this->gRenderer = gRenderer;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->gTexture = this->loadTexture(url);
}

void View::closeImage()
{
    SDL_DestroyTexture(this->gTexture);
    this->gTexture = NULL;
}

#endif

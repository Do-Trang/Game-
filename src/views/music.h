
#include "view.h"
class MusicView : public View
{
public:
    void renderImage();
    void event(SDL_Event *e);
    void init(std::string url2);
    SDL_Texture *gTexture2 = NULL;

    bool isClicked = false;

private:
};

void MusicView::init(std::string url2)
{
    this->gTexture2 = this->loadTexture(url2);
}
void MusicView::renderImage()
{

    SDL_Rect rect = {this->x, this->y, this->w, this->h};
    if (this->isClicked)
        SDL_RenderCopy(this->gRenderer, this->gTexture, NULL, &rect);
    else
        SDL_RenderCopy(this->gRenderer, this->gTexture2, NULL, &rect);
}
void MusicView::event(SDL_Event *e)
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    bool inside = true;

    if (mouse_x < this->x)
    {
        inside = false;
    }
    else if (mouse_x > this->x + this->w)
    {
        inside = false;
    }
    else if (mouse_y < this->y)
    {
        inside = false;
    }
    else if (mouse_y > this->y + this->h)
    {
        inside = false;
    }

    if (inside)
    {
        if (e->type == SDL_MOUSEBUTTONDOWN)
        {
            if (this->isClicked == true)
            {
                isClicked = false;
                this->gMusic = Mix_LoadMUS(MUZIK);
                Mix_PlayMusic(this->gMusic, -1);
            }
            else
            {
                isClicked = true;
                Mix_PauseMusic();
            }
        }
    }

}

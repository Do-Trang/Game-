
#include "view.h"
class LevelButton : public View
{
public:
    void renderImage();
    void event(SDL_Event *e);
    void init(std::string url2,int level);
    SDL_Texture *gTexture2 = NULL;
    bool isHover = false;
    bool isClicked = false;
        bool isplay = false;
        int level = 0;

private:
};

void LevelButton::init(std::string url2,int level)
{
    this->gTexture2 = this->loadTexture(url2);
    this->level = level;
}
void LevelButton::renderImage()
{

    SDL_Rect rect = {this->x, this->y, this->w, this->h};
    if (  this->isHover)
        SDL_RenderCopy(this->gRenderer, this->gTexture, NULL, &rect);
    else
        SDL_RenderCopy(this->gRenderer, this->gTexture2, NULL, &rect);
}
void LevelButton::event(SDL_Event *e)
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
        // di chuot vao hinh anh
        this->isHover = true;
        // click chuot vao hinh anh
        if (e->type == SDL_MOUSEBUTTONDOWN)
        {
            if (this->isClicked == true)
                isplay= false;
            else
                isplay= true;
        }
    }
    else
        this->isHover = false;
}

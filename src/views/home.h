
#include "view.h"
class Home : public View
{
public:
    void renderImage();
    void event(SDL_Event *e);
    bool isback = false;

private:
};

void Home::renderImage()
{

    SDL_Rect rect = {this->x, this->y, this->w, this->h};
    SDL_RenderCopy(this->gRenderer, this->gTexture, NULL, &rect);
}
void Home::event(SDL_Event *e)
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
        // click chuot vao hinh anh
        if (e->type == SDL_MOUSEBUTTONDOWN)
        {
            if (this->isback == true)
                isback = false;
            else
                isback = true;

        }
    }
}

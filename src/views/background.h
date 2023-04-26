
#include "view.h"
class Background : public View
{
public:
    void renderImage();

private:
};

void Background::renderImage()
{

    SDL_Rect rect = {this->x, this->y, this->w, this->h};

    SDL_RenderCopy(this->gRenderer, this->gTexture, NULL, &rect);
}

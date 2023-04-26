
#include "view.h"
#include "../controllers/map.h"
class Cat : public View
{
public:
    void renderImage();
    int level = 0;
    Map *map;
    Background *gvictory;
    void init(int level, Map *map);

    void event(SDL_Event *e);
    SDL_Rect gclip[10 * 10];

private:
};

void Cat::renderImage()
{
    for (int i = 0; i < this->level; i++)
    {
        for (int j = 0; j < this->level; j++)
        {

            if (this->map->a[i][j] != 1000)
            {
                SDL_Rect rect = {this->x + PADDING * j + (this->w / this->level) * j, this->y + PADDING * i + (this->h / this->level) * i, this->w / this->level, this->h / this->level};

                SDL_Rect clip = this->gclip[this->map->a[i][j]];
                SDL_RenderCopy(this->gRenderer, this->gTexture, &clip, &rect);
            }
        }
    }
    this->map->botting();
    if (this->map->isWin())
    {
        this->gvictory->renderImage();
    }
}
void Cat::init(int level, Map *map)
{
    this->map = map;
    this->level = level;
    for (int z = 0; z < this->level * this->level; z++)
    {
        int i = z / this->level;
        int j = z - i * this->level;
        SDL_Rect clip = {PADDING * j + (this->w / this->level) * j, PADDING * i + (this->h / this->level) * i, this->w / this->level, this->h / this->level};

        gclip[z] = clip;
    }
    this->gvictory = new Background();
    this->gvictory->initView(gRenderer, VICTORY, 126, 240, 347, 138);
}
void Cat::event(SDL_Event *e)
{

    const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_UP])
    {
        this->map->move(MOVE_UP);
    }
    else if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        this->map->move(MOVE_DOWN);
    }
    else if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        this->map->move(MOVE_LEFT);
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        this->map->move(MOVE_RIGHT);
    }
}

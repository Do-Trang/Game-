
#ifndef GLOBAL_ListView
#define GLOBAL_ListView
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "views/music.h"
#include "views/view.h"
#include "views/background.h"
#include "views/levelbutton.h"
#include "views/cat.h"
#include "views/home.h"
#include "views/bot.h"
#include "controllers/map.h"
class ListView
{
public:
    ListView(SDL_Renderer *gRenderer);

    void event(SDL_Event *e);
    void renderImage();
    void closeImage();
    Mix_Music *gMusic = NULL;
    MusicView *musicView;
    Background *gbackground;
    Background *title;
    Background *gcatsmall;
    Background *gArrow;
    Cat *gcat;
    Bot *gbot;
    std::vector<LevelButton *> glevelbuttons;
    Home *ghome;
    int level = 0;
    bool isback = false;

    Map *map;

private:
};

ListView::ListView(SDL_Renderer *gRenderer)
{

    this->musicView = new MusicView();
    this->title = new Background();
    this->gbackground = new Background();
    this->gcatsmall = new Background();
    this->gArrow = new Background();
    this->gcat = new Cat();
    this->ghome = new Home();
    this->map = new Map();
    this->gbot = new Bot();

    this->gbackground->initView(gRenderer, BACKGROUND_IMAGE, 0, 0, 600, 600);
    this->gcatsmall->initView(gRenderer, CATSMALL_IMAGE, 0, 500, 100, 100);
    this->gArrow->initView(gRenderer, ARROW, 251, 50, 98, 63);
    this->musicView->initView(gRenderer, MUSICOFFBUTTON_IMAGE, 50, 50, 50, 50);
    this->musicView->init(MUSICBUTTON_IMAGE);
    this->title->initView(gRenderer, TITLE_IMAGE, 114, 70, 371, 111);
    this->gcat->initView(gRenderer, CAT_IMAGE, 125, 150, 350, 350);
    this->ghome->initView(gRenderer, HOME_IMAGE, 500, 50, 50, 50);
    this->gbot->initView(gRenderer, BOT_IMAGE, 220, 500, 162, 100);
    this->gbot->init(BOTDARK_IMAGE);

    this->glevelbuttons.push_back(new LevelButton());
    this->glevelbuttons.push_back(new LevelButton());
    this->glevelbuttons.push_back(new LevelButton());
    this->glevelbuttons.push_back(new LevelButton());
    this->glevelbuttons.push_back(new LevelButton());
    this->glevelbuttons.push_back(new LevelButton());
    this->glevelbuttons.push_back(new LevelButton());
    this->glevelbuttons.push_back(new LevelButton());

    this->glevelbuttons.at(0)->initView(gRenderer, IMAGE_3X3, 25, 200, 155, 111);
    this->glevelbuttons.at(1)->initView(gRenderer, IMAGE_4X4, 225, 200, 161, 111);
    this->glevelbuttons.at(2)->initView(gRenderer, IMAGE_5X5, 425, 200, 155, 111);
    this->glevelbuttons.at(3)->initView(gRenderer, IMAGE_6X6, 25, 300, 158, 111);
    this->glevelbuttons.at(4)->initView(gRenderer, IMAGE_7X7, 225, 300, 157, 111);
    this->glevelbuttons.at(5)->initView(gRenderer, IMAGE_8X8, 425, 300, 159, 111);
    this->glevelbuttons.at(6)->initView(gRenderer, IMAGE_9X9, 25, 400, 158, 111);
    this->glevelbuttons.at(7)->initView(gRenderer, IMAGE_10X10, 200, 400, 220, 111);

    this->glevelbuttons.at(0)->init(IMAGE_3X3DARK, 3);
    this->glevelbuttons.at(1)->init(IMAGE_4X4DARK, 4);
    this->glevelbuttons.at(2)->init(IMAGE_5X5DARK, 5);
    this->glevelbuttons.at(3)->init(IMAGE_6X6DARK, 6);
    this->glevelbuttons.at(4)->init(IMAGE_7X7DARK, 7);
    this->glevelbuttons.at(5)->init(IMAGE_8X8DARK, 8);
    this->glevelbuttons.at(6)->init(IMAGE_9X9DARK, 9);
    this->glevelbuttons.at(7)->init(IMAGE_10X10DARK, 10);

    this->gMusic = Mix_LoadMUS(MUZIK);
    Mix_PlayMusic(this->gMusic, -1);
}

void ListView::renderImage()
{

    this->gbackground->renderImage();
    this->musicView->renderImage();

    if (this->level == 0 || this->ghome->isback == true)
    {
        this->title->renderImage();

        for (auto glevelbutton : this->glevelbuttons)
        {
            glevelbutton->renderImage();
            if (glevelbutton->isplay)
            {
                this->level = glevelbutton->level;
                this->map->init(level);
                this->gcat->init(level, this->map);
                this->ghome->isback = false;
                this->gbot->isBot = false;
                this->map->move_point = this->level * NUMBER;
                glevelbutton->isplay = false;
            }
        }
    }
    else
    {
        this->gcat->renderImage();
        this->gcatsmall->renderImage();
        this->gArrow->renderImage();
        this->ghome->renderImage();
        this->gbot->renderImage();
    }
}

void ListView::event(SDL_Event *e)
{
    this->musicView->event(e);
    for (auto glevelbutton : this->glevelbuttons)
    {
        glevelbutton->event(e);
    }
    this->ghome->event(e);
    this->gbot->event(e);

    this->map->isBot = this->gbot->isBot;
    this->gcat->event(e);
}

void ListView::closeImage()
{
    this->musicView->closeImage();
    this->gbackground->closeImage();
    this->title->closeImage();
    this->gcat->closeImage();
    this->gcatsmall->closeImage();
    this->gArrow->closeImage();
    this->ghome->closeImage();
    this->gbot->closeImage();
    for (auto glevelbutton : this->glevelbuttons)
    {
        glevelbutton->closeImage();
    }
}
#endif

#include "init_sdl.h"

int main(int argc, char *args[])
{
    INIT_SDL3 *initSdl = new INIT_SDL3();
    initSdl->start();
    return 0;
}

#include <stdio.h>
#include "funcs/init.h"
#include "funcs/event.h"
#include "funcs/motion.h"
#include "funcs/renderer.h"

int main(int argc, const char** argv) {
    if (!init()) {
        printf("SYSTEM INIT FAILED!\n");
    }
    else {
        int granules = 20;
        SDL_Texture* space;

        // Set Target
        space = fixedSpace(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_PIXELFORMAT_RGBA8888);
        setTarget(space);
        drawSpace(granules);

        // ---------------------------------- //
        // drawRects(Rects, TotalRectsSubPos);
        // ---------------------------------- //

        // Clear Target
        setTarget(NULL);

        // drawFlower();
        eventLoop(space, granules);
    }

    return 0;
}
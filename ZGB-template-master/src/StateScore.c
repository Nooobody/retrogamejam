#include "Banks/SetBank2.h"

#include <stdlib.h>

#include "..\res\src\tiles.h"
#include "..\res\src\score.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Keys.h"

#include "Print.h"
#include "../res/src/font.h"

void Start_StateScore()
{
    UINT8 i;

    InitScrollTiles(0, &font);
    InitScroll(&score, 0, 0);
    SpriteManagerAdd(SpriteOne, 0, 0);
    SHOW_BKG;
    INIT_CONSOLE(font, 3, 2);
    MoveScroll(8, 8);
}

void Update_StateScore()
{
    if (KEY_PRESSED(J_START))
    {
        SetState(StateGame);
    }
}
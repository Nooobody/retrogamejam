#include "Banks/SetBank2.h"

#include <stdlib.h>

#include "..\res\src\tiles.h"
#include "..\res\src\intro.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Keys.h"

#include "Print.h"
#include "../res/src/font.h"

void Start_StateIntro()
{
    UINT8 i;

    SPRITES_8x16;
    for (i = 0; i != N_SPRITE_TYPES; ++i)
    {
        SpriteManagerLoad(i);
    }
    SHOW_SPRITES;
    //scroll_target =
    //SpriteManagerAdd(SpritePlayer, 50, 130);
    //SpriteManagerAdd(SpriteEnemy, 70, 50);

    //SpriteManagerAdd(SpriteStars, rand() % 120 + 30, 10);
    //SpriteManagerAdd(SpriteStars, rand() % 120 + 30, 10);
    //SpriteManagerAdd(SpriteStars, rand() % 120 + 30, 10);

    InitScrollTiles(0, &font);
    InitScroll(&intro, 0, 0);
    SHOW_BKG;
    INIT_CONSOLE(font, 3, 2);
    MoveScroll(8, 8);
}

void Update_StateIntro()
{
    if (KEY_PRESSED(J_START))
    {
        SetState(StateGame);
    }
}
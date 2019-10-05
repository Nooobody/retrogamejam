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
    UINT8 i = 0;
    UINT16 tempScore = playerScore;
    for (i; i < 5; ++i)
    {
        int digit = tempScore % 10;
        tempScore /= 10;

        switch (digit) {
          case 1:
            SpriteManagerAdd(SpriteOne, 120 - 8 * i, 56);
            break;
          case 2:
            SpriteManagerAdd(SpriteTwo, 120 - 8 * i, 56);
            break;
          case 3:
            SpriteManagerAdd(SpriteThree, 120 - 8 * i, 56);
            break;
          case 4:
            SpriteManagerAdd(SpriteFour, 120 - 8 * i, 56);
            break;
          case 5:
            SpriteManagerAdd(SpriteFive, 120 - 8 * i, 56);
            break;
          case 6:
            SpriteManagerAdd(SpriteSix, 120 - 8 * i, 56);
            break;
          case 7:
            SpriteManagerAdd(SpriteSeven, 120 - 8 * i, 56);
            break;
          case 8:
            SpriteManagerAdd(SpriteEight, 120 - 8 * i, 56);
            break;
          case 9:
            SpriteManagerAdd(SpriteNine, 120 - 8 * i, 56);
            break;
          case 0:
          default:
            SpriteManagerAdd(SpriteZero, 120 - 8 * i, 56);
            break;
        }
    }

    InitScrollTiles(0, &font);
    InitScroll(&score, 0, 0);
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

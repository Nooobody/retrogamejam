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
    char *scoreText;
    UIntToString(playerScore, scoreText);
    for (i; i < 5; ++i)
    {
        if (scoreText[i] == '\0')
        {
            break;
        }
        if (scoreText[i] == '1')
        {
            SpriteManagerAdd(SpriteOne, 8 * i, 0);
        }
        else if (scoreText[i] == '2')
        {
            SpriteManagerAdd(SpriteTwo, 8 * i, 0);
        }
        else if (scoreText[i] == '3')
        {
            SpriteManagerAdd(SpriteThree, 8 * i, 0);
        }
        else if (scoreText[i] == '4')
        {
            SpriteManagerAdd(SpriteFour, 8 * i, 0);
        }
        else if (scoreText[i] == '5')
        {
            SpriteManagerAdd(SpriteFive, 8 * i, 0);
        }
        else if (scoreText[i] == '6')
        {
            SpriteManagerAdd(SpriteSix, 8 * i, 0);
        }
        else if (scoreText[i] == '7')
        {
            SpriteManagerAdd(SpriteSeven, 8 * i, 0);
        }
        else if (scoreText[i] == '8')
        {
            SpriteManagerAdd(SpriteEight, 8 * i, 0);
        }
        else if (scoreText[i] == '9')
        {
            SpriteManagerAdd(SpriteNine, 8 * i, 0);
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
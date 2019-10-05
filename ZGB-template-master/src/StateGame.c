#include "Banks/SetBank2.h"

#include <stdlib.h>

#include "..\res\src\tiles.h"
#include "..\res\src\scrollingmap.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Sound.h"

#include "Print.h"
#include "../res/src/font.h"

UINT8 collision_tiles[] = {1, 0};
UINT8 time = 0;

extern UINT8 vittujes_mod_data[];

void Start_StateGame()
{
	UINT8 i;
        time = 0;

	SPRITES_8x16;
	for (i = 0; i != N_SPRITE_TYPES; ++i)
	{
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;
	//scroll_target =
	SpriteManagerAdd(SpritePlayer, 50, 130);

	SpriteManagerAdd(SpriteStars, rand() % 120 + 30, 10);
	SpriteManagerAdd(SpriteStars, rand() % 120 + 30, 100);

	InitScrollTiles(0, &tiles);
	InitScroll(&scrollingmap, collision_tiles, 0);
	SHOW_BKG;
	INIT_CONSOLE(font, 3, 2);
	MoveScroll(8, 16);

        PlayMusic(vittujes_mod_data, 3, 1);
}

void Update_StateGame()
{
	if (time % 120 == 0)
	{
          switch (rand() % 3) {
            case 0:
		SpriteManagerAdd(SpriteEnemy, 84 + rand() % 120 - 60, 0);
                break;
            case 1:
		SpriteManagerAdd(SpriteEnemy2, 84 + rand() % 120 - 60, 0);
                break;
            case 2:
            default:
                SpriteManagerAdd(SpriteEnemy3, 84 + rand() % 120 - 60, 0);
          }
          PlayFx(CHANNEL_4, 4, 0x0c, 0x41, 0x30, 0xc0);
          time = 0;
	}
	time++;
}

#include "Banks/SetBank2.h"

#include <stdlib.h>

#include "..\res\src\tiles.h"
#include "..\res\src\scrollingmap.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

#include "Print.h"
#include "../res/src/font.h"

UINT8 collision_tiles[] = {1, 0};
UINT8 time = 0;

void Start_StateGame()
{
	UINT8 i;

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
}

void Update_StateGame()
{
	if (time % 1000 == 0)
	{
          switch (rand() % 3) {
            case 0:
		SpriteManagerAdd(SpriteEnemy, rand() % 120 + 28, 0);
                break;
            case 1:
		SpriteManagerAdd(SpriteEnemy2, rand() % 120 + 28, 0);
                break;
            case 2:
            default:
                SpriteManagerAdd(SpriteEnemy3, rand() % 120 + 28, 0);
          }
          time = 0;
	}
	time++;
}

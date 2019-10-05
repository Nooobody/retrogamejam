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

	InitScrollTiles(0, &tiles);
	InitScroll(&scrollingmap, collision_tiles, 0);
	SHOW_BKG;
	INIT_CONSOLE(font, 3, 2);
<<<<<<< HEAD
	MoveScroll(8, 8);
=======
	MoveScroll(8, 16);
>>>>>>> 40564a285723b9c4933df82c70f3d4a6d63b24a7
}

void Update_StateGame()
{
	if (time % 10000 == 0)
	{
		SpriteManagerAdd(SpriteEnemy, 70, 16);
	}
	time++;
}

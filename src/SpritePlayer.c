#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"
#include "Sound.h"

UINT8 frameCount = 0;
UINT8 shootFrameCount = 0;
UINT8 scoreFrameCount = 0;
UINT8 bulletCount;
UINT8 playerScore;
UINT8 enemyBulletCount;
UINT8 playerX;
UINT8 playerY;

BOOLEAN shooting;

void Start_SpritePlayer()
{
	bulletCount = 0;
	playerScore = 0;
	shooting = FALSE;
	enemyBulletCount = 0;
}

void Update_SpritePlayer()
{
	UINT8 i;
	struct Sprite *spr;

	if (scoreFrameCount % 60 == 0)
	{
		playerScore += 1;
		scoreFrameCount = 0;
	}

	scoreFrameCount++;
	if (KEY_PRESSED(J_UP))
	{
		TranslateSprite(THIS, 0, -1 << delta_time);
	}
	if (KEY_PRESSED(J_DOWN))
	{
		TranslateSprite(THIS, 0, 1 << delta_time);
	}
	if (KEY_PRESSED(J_LEFT))
	{
		TranslateSprite(THIS, -2 << delta_time, 0);
	}
	if (KEY_PRESSED(J_RIGHT))
	{
		TranslateSprite(THIS, 2 << delta_time, 0);
	}
	if (KEY_PRESSED(J_B))
	{
		shooting = TRUE;
	}
	else if (shooting)
	{
		shooting = FALSE;
	}

	if (shooting)
	{
		if (shootFrameCount % 20 == 0)
		{
			if (bulletCount < 1)
			{
				SpriteManagerAdd(SpriteBullet, playerX, playerY - 8);
				bulletCount++;
			}
		}
		shootFrameCount++;
	}
	else if (shootFrameCount % 20 > 0)
	{
		shootFrameCount++;
		if (shootFrameCount % 20 == 0)
		{
			shootFrameCount = 0;
		}
	}

	if (frameCount > 100)
	{
		frameCount = 0;
	}
	frameCount++;

	if (shootFrameCount == 100)
	{
		shootFrameCount = 0;
	}

	SPRITEMANAGER_ITERATE(i, spr)
	{
		if (spr->type == SpriteEnemy || 
                    spr->type == SpriteEnemy2 || 
                    spr->type == SpriteEnemy3 || 
                    spr->type == SpriteEnemyBulletLeft ||
                    spr->type == SpriteEnemyBulletRight)
		{
			if (CheckCollision(THIS, spr))
			{
				SpriteManagerRemoveSprite(THIS);
				//SetState(StateScore);
			}
		}
	}
	DPRINT_POS(0, 0);

	playerX = THIS->x;
	playerY = THIS->y;
}

void Destroy_SpritePlayer()
{
	PlayFx(CHANNEL_1, 10, 0x4f, 0xc7, 0xf3, 0x73, 0x86);
	SpriteManagerAdd(SpritePlayerkys, THIS->x, THIS->y);
}



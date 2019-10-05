#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

const UINT8 anim_idle[] = {1, 0}; //The first number indicates the number of frames
const UINT8 anim_walk[] = {2, 1, 2};
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
		playerScore += 10;
		scoreFrameCount = 0;
	}

	scoreFrameCount++;
	if (KEY_PRESSED(J_UP))
	{
		TranslateSprite(THIS, 0, -1);
	}
	if (KEY_PRESSED(J_DOWN))
	{
		TranslateSprite(THIS, 0, 1);
	}
	if (KEY_PRESSED(J_LEFT))
	{
		TranslateSprite(THIS, -1, 0);
	}
	if (KEY_PRESSED(J_RIGHT))
	{
		TranslateSprite(THIS, 1, 0);
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
			if (bulletCount < 4)
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

	if (keys == 0)
	{
		SetSpriteAnim(THIS, anim_idle, 15);
	}
	SPRITEMANAGER_ITERATE(i, spr)
	{
		if (spr->type == SpriteEnemy || spr->type == SpriteEnemyBullet)
		{
			if (CheckCollision(THIS, spr))
			{
				SetState(StateScore);
			}
		}
	}
	DPRINT_POS(0, 0);

	playerX = THIS->x;
	playerY = THIS->y;
}

void Destroy_SpritePlayer()
{
}


#ifndef ENEMYBASE
#define ENEMYBASE

#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "EnemyBase.h"

void EnemyStart(struct Sprite* THIS) {
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;
    data->vx = 1;
    data->vy = 1;
    data->frameCount = 1;
    data->hitFrame = 150 + rand() % 40 - 20;
    data->health = 3;
}

void EnemyUpdate(struct Sprite* THIS) {
    struct Sprite *spr;
    UINT8 i;
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;

    if (THIS->y < 24)
    {
        if (TranslateSprite(THIS, data->vx << delta_time, 1 << delta_time))
        {
            data->vx = -data->vx;
        }
    }
    else if (THIS->y < 140)
    {
        if (TranslateSprite(THIS, data->vx << delta_time, data->vy << delta_time))
        {
            data->vx = -data->vx;
        }
    }
    else
    {
        THIS->x += data->vx << delta_time;
        THIS->y += data->vy << delta_time;
    }

    SPRITEMANAGER_ITERATE(i, spr)
    {
        if (spr->type == SpriteBullet)
        {
            if (CheckCollision(THIS, spr))
            {
                data->health -= 1;
                SpriteManagerRemoveSprite(spr);
                if (data->health == 0)
                {
                    playerScore += 5;
                    SpriteManagerAdd(SpriteEnemykys, THIS->x, THIS->y);
                    SpriteManagerRemoveSprite(THIS);
                }
            }
        }
    }

    if (data->frameCount == data->hitFrame && enemyBulletCount < 3)
    {
        SpriteManagerAdd(SpriteEnemyBullet, THIS->x, THIS->y + 16);
        enemyBulletCount++;
        data->frameCount = 0;
    }
    data->frameCount++;
}

void EnemyDestroy(struct Sprite* THIS) {
}

#endif


#ifndef ENEMYBASE
#define ENEMYBASE

#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "EnemyBase.h"
#include "rand.h"

const UINT8 enemy_hit_anim[] = {2, 0, 1}; //The first number indicates the number of frames
const UINT8 enemy_idle[] = {1, 0};

void EnemyStart(struct Sprite* THIS) {
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;
    data->vx = randw() % 2 == 0 ? 1 : -1;
    data->vy = 1;
    data->health = 3;
    data->hasFired = FALSE;
    data->hitAnim = FALSE;
    data->hitFrameCount = 0;
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
                data->hitAnim = TRUE;
                data->hitFrameCount = 0;
                SpriteManagerRemoveSprite(spr);
                if (data->health == 0)
                {
                    playerScore += 5;
                    SpriteManagerAdd(SpriteEnemykys, THIS->x, THIS->y);
                    SpriteManagerRemoveSprite(THIS);
                }
            }
        }
        else if (spr->type == SpritePlayer && !data->hasFired) {
            if (spr->y == THIS->y && enemyBulletCount < 3)
            {
                if (spr->x < THIS->x) {
                    SpriteManagerAdd(SpriteEnemyBulletLeft, THIS->x - 8, THIS->y);
                }
                else {
                    SpriteManagerAdd(SpriteEnemyBulletRight, THIS->x + 8, THIS->y);
                }
                enemyBulletCount++;
                data->hasFired = TRUE;
            }
        }
    }

    if (data->hitAnim) {
        // SetSpriteAnim(THIS, enemy_hit_anim, 30);
        if (data->hitFrameCount == 10) {
            data->hitAnim = FALSE;
            SetSpriteAnim(THIS, enemy_idle, 30);
        }
        data->hitFrameCount++;
    }
    else {
      SetSpriteAnim(THIS, enemy_idle, 30);
    }
}

void EnemyDestroy(struct Sprite* THIS) {
}

#endif

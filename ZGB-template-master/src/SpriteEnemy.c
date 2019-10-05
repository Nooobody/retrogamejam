#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

struct EnemyInfo
{
    INT8 vx;
    INT8 vy;
    UINT16 frameCount;
    UINT8 hitFrame;
};

void Start_SpriteEnemy()
{
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;
    data->vx = 1;
    data->vy = 0;
    data->frameCount = 1;
    data->hitFrame = 150 + rand() % 40 - 20;
}

void Update_SpriteEnemy()
{
    struct Sprite *spr;
    UINT8 i;
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;

    if (THIS->y < 24) {
      THIS->x += 1;
      THIS->y += 1;
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
                SpriteManagerAdd(SpriteEnemykys, THIS->x, THIS->y);
                SpriteManagerRemoveSprite(spr);
                SpriteManagerRemoveSprite(THIS);
            }
        }
    }

    if (data->frameCount == data->hitFrame && enemyBulletCount < 3) {
      SpriteManagerAdd(SpriteEnemyBullet, THIS->x, THIS->y + 16);
      enemyBulletCount++;
      data->frameCount = 0;
    } 
    data->frameCount++;
}

void Destroy_SpriteEnemy()
{
}

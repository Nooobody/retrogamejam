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
};

void Start_SpriteEnemy()
{
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;
    data->vx = 2;
    data->vy = 0;
    data->frameCount = 0;
}

void Update_SpriteEnemy()
{
    struct Sprite *spr;
    UINT8 i;
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;

    if (THIS->y < 140)
    {
        if (TranslateSprite(THIS, data->vx, data->vy))
        {
            data->vx = -data->vx;
        }
    }
    else
    {
        THIS->x += data->vx;
        THIS->y += data->vy;
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

    if (data->frameCount % 150 == 0 && enemyBulletCount < 3) {
      SpriteManagerAdd(SpriteEnemyBullet, THIS->x, THIS->y + 16);
      enemyBulletCount++;
    } 

    data->frameCount++;
    if (data->frameCount == 300) {
      data->frameCount = 0;
    }
}

void Destroy_SpriteEnemy()
{
}

#include "Banks/SetBank2.h"

#include "Print.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

struct BulletInfo
{
    INT8 vx;
};

void Start_SpriteEnemyBulletRight()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    data->vx = 2;

    THIS->coll_x = 0;
    THIS->coll_y = 4;
    THIS->coll_w = 8;
    THIS->coll_h = 8;
}

void Update_SpriteEnemyBulletRight()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    THIS->x += data->vx << delta_time;
    // if (TranslateSprite(THIS, 0, data->vy))
    // {
    // SpriteManagerRemoveSprite(THIS);
    // }
}

void Destroy_SpriteEnemyBulletRight()
{
    enemyBulletCount--;
}

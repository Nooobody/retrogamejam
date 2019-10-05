#include "Banks/SetBank2.h"

#include "Print.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

struct BulletInfo
{
    INT8 vy;
};

void Start_SpriteEnemyBullet()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    data->vy = 2;
}

void Update_SpriteEnemyBullet()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    THIS->y += 2;
    // if (TranslateSprite(THIS, 0, data->vy))
    // {
        // SpriteManagerRemoveSprite(THIS);
    // }
}

void Destroy_SpriteEnemyBullet()
{
    enemyBulletCount--;
}


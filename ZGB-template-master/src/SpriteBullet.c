#include "Banks/SetBank2.h"

#include "Print.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
struct BulletInfo
{
    INT8 vx;
    INT8 vy;
};

void Start_SpriteBullet()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    data->vy = -1;
}

void Update_SpriteBullet()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    TranslateSprite(THIS, 0, data->vy);
    if (TranslateSprite(THIS, data->vx, data->vy))
    {
        SpriteManagerRemoveSprite(THIS);
        bulletCount--;
    }
}

void Destroy_SpriteBullet()
{
}
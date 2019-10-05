#include "Banks/SetBank2.h"

#include "Print.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
struct BulletInfo
{
    INT8 vy;
};

void Start_SpriteBullet()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    data->vy = -8;
}

void Update_SpriteBullet()
{
    struct BulletInfo *data = (struct BulletInfo *)THIS->custom_data;
    if (TranslateSprite(THIS, 0, data->vy))
    {
        SpriteManagerRemoveSprite(THIS);
    }
}

void Destroy_SpriteBullet()
{
    bulletCount--;
}
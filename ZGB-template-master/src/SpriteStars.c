#include "Banks/SetBank2.h"

#include "Print.h"
#include "SpriteManager.h"

#include "ZGBMain.h"

UINT8 frameCount = 0;

struct StarInfo {
  UINT8 vy;
};

void Start_SpriteStar()
{
    struct StarInfo *data = (struct StarInfo *)THIS->custom_data;
    data->vy = rand() % 10;
}

void Update_SpriteStar()
{
    struct StarInfo *data = (struct StarInfo *)THIS->custom_data;
    if (frameCount % data->vy == 0 && TranslateSprite(THIS, 0, 1))
    {
        SpriteManagerRemoveSprite(THIS);
    }
    frameCount++;
}

void Destroy_SpriteStar()
{
    SpriteManagerAdd(SpriteStar, rand() % 140 + 10, 10);
}


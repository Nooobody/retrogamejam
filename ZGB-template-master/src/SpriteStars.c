#include "Banks/SetBank2.h"
#include <stdlib.h>
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

UINT8 frameCount = 0;

struct StarInfo
{
    UINT8 vy;
};

void Start_SpriteStars()
{
    struct StarInfo *data = (struct StarInfo *)THIS->custom_data;
    //data->vy = rand() % 2 + 1;
    data->vy = 1;
}

void Update_SpriteStars()
{
    struct StarInfo *data = (struct StarInfo *)THIS->custom_data;
    if (frameCount % data->vy == 0 && TranslateSprite(THIS, 0, 1))
    {
        SpriteManagerRemoveSprite(THIS);
    }
    frameCount++;
}

void Destroy_SpriteStars()
{
    SpriteManagerAdd(SpriteStars, rand() % 120 + 30, 10);
}

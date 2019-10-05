#include "Banks/SetBank2.h"
#include <stdlib.h>
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

UINT8 frameCount = 0;
const UINT8 anim_idle[] = {2, 0, 1}; //The first number indicates the number of frames

struct StarInfo
{
    UINT8 vy;
};

void Start_SpriteStars()
{
    struct StarInfo *data = (struct StarInfo *)THIS->custom_data;
    data->vy = rand() % 2;
}

void Update_SpriteStars()
{
    struct StarInfo *data = (struct StarInfo *)THIS->custom_data;
    if (frameCount % data->vy == 0 && TranslateSprite(THIS, 0, 1))
    {
        SpriteManagerRemoveSprite(THIS);
    }
    frameCount++;
    SetSpriteAnim(THIS, anim_idle, 15);
}

void Destroy_SpriteStars()
{
    SpriteManagerAdd(SpriteStars, rand() % 120 + 30, 10);
}

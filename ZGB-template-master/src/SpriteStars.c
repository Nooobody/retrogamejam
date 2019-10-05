#include "Banks/SetBank2.h"
#include <stdlib.h>
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

UINT8 frameCount = 0;

struct StarInfo {
  UINT8 vy;
};

void Start_SpriteStar()
{
    struct StarInfo *data = (struct StarInfo *)THIS->custom_data;
    data->vy = rand() % 5;
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
    SpriteManagerAdd(SpriteStar, rand() % 120 + 30, 10);
}


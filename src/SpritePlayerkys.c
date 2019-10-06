#include "Banks/SetBank2.h"
#include <stdlib.h>
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

const UINT8 player_anim_kys[] = {7, 0, 1, 2, 3, 4, 5, 6}; //The first number indicates the number of frames

struct KysData
{
    UINT8 frameCount;
};

void Start_SpritePlayerkys()
{
    struct KysData *data = (struct KysData *)THIS->custom_data;
    data->frameCount = 0;
}

void Update_SpritePlayerkys()
{
    struct KysData *data = (struct KysData *)THIS->custom_data;
    data->frameCount++;
    if (data->frameCount > 45)
    {
        SpriteManagerRemoveSprite(THIS);
    }
    SetSpriteAnim(THIS, player_anim_kys, 15);
}

void Destroy_SpritePlayerkys()
{
    SetState(StateScore);
}

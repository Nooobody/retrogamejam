#include "Banks/SetBank2.h"
#include <stdlib.h>
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

const UINT8 enemy_anim_kys[] = {5, 0, 1, 2, 3, 4}; //The first number indicates the number of frames

struct KysData {
  UINT8 frameCount;
};

void Start_SpriteEnemykys()
{
  struct KysData *data = (struct KysData *)THIS->custom_data;
  data->frameCount = 0;
}

void Update_SpriteEnemykys()
{
    struct KysData *data = (struct KysData *)THIS->custom_data;
    data->frameCount++;
    if (data->frameCount > 30)
    {
        SpriteManagerRemoveSprite(THIS);
    }
    SetSpriteAnim(THIS, enemy_anim_kys, 15);
}

void Destroy_SpriteEnemykys()
{
}

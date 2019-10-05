#include "Banks/SetBank2.h"
#include <stdlib.h>
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"

const UINT8 enemy_anim_kys[] = {5, 0, 1, 2, 3, 4}; //The first number indicates the number of frames

UINT8 frameCount = 0;

void Start_SpriteEnemykys()
{
}

void Update_SpriteEnemykys()
{
    frameCount++;
    if (frameCount > 30)
    {
        SpriteManagerRemoveSprite(THIS);
    }
    SetSpriteAnim(THIS, enemy_anim_kys, 15);
}

void Destroy_SpriteEnemykys()
{
}
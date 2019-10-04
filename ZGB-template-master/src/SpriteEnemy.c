#include "Banks/SetBank2.h"

#include "Print.h"
#include "SpriteManager.h"

struct EnemyInfo
{
    INT8 vx;
    INT8 vy;
};

void Start_SpriteEnemy()
{
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;
    data->vx = 2;
    data->vy = 1;
}

void Update_SpriteEnemy()
{
    struct EnemyInfo *data = (struct EnemyInfo *)THIS->custom_data;
    if (TranslateSprite(THIS, data->vx, data->vy))
    {
        data->vx = -data->vx;
    }
    DPrintf("x:%d y:%d  ", THIS->x, THIS->y);
}

void Destroy_SpriteEnemy()
{
}
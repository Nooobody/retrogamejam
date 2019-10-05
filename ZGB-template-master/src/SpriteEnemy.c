#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "EnemyBase.h"

void Start_SpriteEnemy()
{
  EnemyStart(THIS);
}

void Update_SpriteEnemy()
{
  EnemyUpdate(THIS);
}

void Destroy_SpriteEnemy()
{
  EnemyDestroy(THIS);
}

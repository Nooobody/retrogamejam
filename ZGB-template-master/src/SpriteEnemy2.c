#include "Banks/SetBank2.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "EnemyBase.h"

void Start_SpriteEnemy2()
{
  EnemyStart(THIS);
}

void Update_SpriteEnemy2()
{
  EnemyUpdate(THIS);
}

void Destroy_SpriteEnemy2()
{
  EnemyDestroy(THIS);
}

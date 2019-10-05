#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES         \
    _STATE(StateIntro) \
    _STATE(StateGame)  \
    STATE_DEF_END

#define SPRITES                           \
    _SPRITE_DMG(SpritePlayer, player)     \
    _SPRITE_DMG(SpriteEnemy, enemy)       \
    _SPRITE_DMG(SpriteBullet, bullet)     \
    _SPRITE_DMG(SpriteEnemyBullet, enemybullet)     \
    _SPRITE_DMG(SpriteStars, stars)       \
    _SPRITE_DMG(SpriteEnemykys, enemykys) \
    SPRITE_DEF_END

#include "ZGBMain_Init.h"
extern UINT8 bulletCount;
extern UINT8 enemyBulletCount;

#endif

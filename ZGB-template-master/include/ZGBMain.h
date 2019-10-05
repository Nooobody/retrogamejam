#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES         \
    _STATE(StateIntro) \
    _STATE(StateGame)  \
    _STATE(StateScore) \
    STATE_DEF_END

#define SPRITES                                 \
    _SPRITE_DMG(SpritePlayer, player)           \
    _SPRITE_DMG(SpriteEnemy, enemy)             \
    _SPRITE_DMG(SpriteEnemy2, enemy2)             \
    _SPRITE_DMG(SpriteEnemy3, enemy3)             \
    _SPRITE_DMG(SpriteBullet, bullet)           \
    _SPRITE_DMG(SpriteEnemyBullet, enemybullet) \
    _SPRITE_DMG(SpriteStars, stars)             \
    _SPRITE_DMG(SpriteEnemykys, enemykys)       \
    _SPRITE_DMG(SpritePlayerkys, playerkys)     \
    SPRITE_DEF_END

#include "ZGBMain_Init.h"

extern UINT8 bulletCount;
extern UINT8 enemyBulletCount;
extern UINT8 playerScore;

#endif

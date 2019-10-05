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
    _SPRITE_DMG(SpriteEnemy2, enemy2)           \
    _SPRITE_DMG(SpriteEnemy3, enemy3)           \
    _SPRITE_DMG(SpriteEnemy4, enemy4)           \
    _SPRITE_DMG(SpriteBullet, bullet)           \
    _SPRITE_DMG(SpriteEnemyBullet, enemybullet) \
    _SPRITE_DMG(SpriteStars, stars)             \
    _SPRITE_DMG(SpriteEnemykys, enemykys)       \
    _SPRITE_DMG(SpritePlayerkys, playerkys)     \
    _SPRITE_DMG(SpriteOne, one)                 \
    _SPRITE_DMG(SpriteTwo, two)                 \
    _SPRITE_DMG(SpriteThree, three)             \
    _SPRITE_DMG(SpriteFour, four)               \
    _SPRITE_DMG(SpriteFive, five)               \
    _SPRITE_DMG(SpriteSix, six)                 \
    _SPRITE_DMG(SpriteSeven, seven)             \
    _SPRITE_DMG(SpriteEight, eight)             \
    _SPRITE_DMG(SpriteNine, nine)               \
    _SPRITE_DMG(SpriteZero, zero)               \
    SPRITE_DEF_END

#include "ZGBMain_Init.h"

extern UINT8 bulletCount;
extern UINT8 enemyBulletCount;
extern UINT8 playerScore;
extern UINT8 spawnCounter;

#endif

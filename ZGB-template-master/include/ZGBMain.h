#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES        \
    _STATE(StateGame) \
    STATE_DEF_END

#define SPRITES                       \
    _SPRITE_DMG(SpritePlayer, player) \
    _SPRITE_DMG(SpriteEnemy, enemy)   \
    _SPRITE_DMG(SpriteBullet, bullet) \
    _SPRITE_DMG(SpriteStar, star)     \
    SPRITE_DEF_END

#include "ZGBMain_Init.h"
extern UINT8 bulletCount;

#endif

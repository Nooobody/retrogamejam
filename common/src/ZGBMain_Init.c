#pragma bank 1
#include "ZGBMain.h"

#define _STATE(STATE_ID) DECLARE_STATE(STATE_ID);
STATES
#undef _STATE

UINT8 stateBanks[N_STATES];

#define _STATE(STATE_ID) Start_##STATE_ID,
Void_Func_Void startFuncs[] = {STATES};
#undef _STATE

#define _STATE(STATE_ID) Update_##STATE_ID,
Void_Func_Void updateFuncs[] = {STATES};
#undef _STATE

#define _STATE(STATE_ID) stateBanks[STATE_ID] = bank_##STATE_ID;
void InitStates() {
	STATES
}
#undef _STATE

//-------------------------------------------------------------------------------------------------
#include "TilesInfo.h"
#define _SPRITE(SPRITE_ID, DATA) DECLARE_SPRITE(SPRITE_ID); extern UINT8 bank_##DATA;
SPRITES
#undef _SPRITE

#define _SPRITE(SPRITE_ID, DATA) extern struct TilesInfo DATA;
SPRITES
#undef _SPRITE

UINT8 spriteBanks[N_SPRITE_TYPES];
UINT8 spriteDataBanks[N_SPRITE_TYPES];

#define _SPRITE(SPRITE_ID, DATA) Start_##SPRITE_ID,
Void_Func_Void spriteStartFuncs[] = {SPRITES};
#undef _SPRITE

#define _SPRITE(SPRITE_ID, DATA) Update_##SPRITE_ID,
Void_Func_Void spriteUpdateFuncs[] = {SPRITES};
#undef _SPRITE

#define _SPRITE(SPRITE_ID, DATA) Destroy_##SPRITE_ID,
Void_Func_Void spriteDestroyFuncs[] = {SPRITES};
#undef _SPRITE

#define _SPRITE(SPRITE_ID, DATA) (struct TilesInfoInternal*)(void*)DATA.data,
struct TilesInfoInternal* spriteDatas[] = {SPRITES};
#undef _SPRITE

//#define _SPRITE(SPRITE_ID, DATA) SIZE,
//FrameSize spriteFrameSizes[] = {SPRITES};
//#undef _SPRITE

//#define _SPRITE(SPRITE_ID, DATA) (NFRAMES << SIZE),
//UINT8 spriteNumFrames[] = {SPRITES};
//#undef _SPRITE

UINT8 spriteIdxs[N_SPRITE_TYPES];

//#define _SPRITE(SPRITE_ID, DATA) PAL_DATA,
//UINT8* spritePalDatas[] = {SPRITES};
//#undef _SPRITE

#define _SPRITE(SPRITE_ID, DATA) spriteBanks[SPRITE_ID] = bank_##SPRITE_ID; spriteDataBanks[SPRITE_ID] = DATA.bank;
void InitSprites() {
	SPRITES
}
#undef _SPRITE

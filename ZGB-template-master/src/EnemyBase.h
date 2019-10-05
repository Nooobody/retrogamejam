
void EnemyStart(struct Sprite*);
void EnemyUpdate(struct Sprite*);
void EnemyDestroy(struct Sprite*);

struct EnemyInfo
{
    INT8 vx;
    INT8 vy;
    UINT16 frameCount;
    UINT8 hitFrame;
    UINT8 health;
};

#ifndef __ENEMY_PLATFORM_H__
#define __ENEMY_PLATFORM_H__

#include "Enemy.h"
#include "PlatformBase.h"

class Platform : public Enemy
{
private:

	int original_y = 100;
	int original_x = 100;

	Animation idle;

public:

	Platform(int x, int y);

	void Move();
};

#endif // __ENEMY_PLATFORM_H__
#ifndef __ENEMY_LAND1_H__
#define __ENEMY_LAND1_H__

#include "Enemy.h"

class Enemy_Land1 : public Enemy
{
private:

	int original_y = 100;
	int original_x = 100;
	int distance;
	bool going_right = true;

	Animation walk;
	Animation die;

public:

	Enemy_Land1(int x, int y);

	void Move();
};

#endif // __ENEMY_LAND1_H__
#ifndef __ENEMY_LAND1_H__
#define __ENEMY_LAND1_H__

#include "Enemy.h"

class Enemy_Land1 : public Enemy
{
private:
	//float wave = -1.0f;
	//int original_y = 0;
	//Animation fly;

	//bool going_left = true;
	//bool going_right = false;
	int original_y = 100;
	int original_x = 100;
	int walk_speed = 1;
	int distance = 0;
	Animation walk;

public:

	Enemy_Land1(int x, int y);

	void Move();
};

#endif // __ENEMY_LAND1_H__
#ifndef __ENEMY_TURRET1_H__
#define __ENEMY_TURRET1_H__

#include "Enemy.h"

class Enemy_Turret1 : public Enemy
{
private:

	int original_y = 100;
	int original_x = 100;

	bool turret_shot;


	Animation idle;
	Animation shoot;
	Animation turret_particle;
	Animation die;

public:

	Enemy_Turret1(int x, int y);

	void Move();
};

#endif // __ENEMY_TURRET1_H__
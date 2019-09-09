#include "Application.h"
#include "Enemy_Land1.h"
#include "ModuleCollision.h"

Enemy_Land1::Enemy_Land1(int x, int y) : Enemy(x, y)
{

	original_y = y;
	original_x = x;
	distance = 0;

	//Idle
	walk.PushBack({ 236, 6, 24, 24 });
	walk.PushBack({ 236, 6, 24, 24 });
	walk.speed = 0.2f;

	animation = &walk;


	//Die
	die.PushBack({ 236, 6, 24, 24 });
	die.PushBack({ 236, 6, 24, 24 });
	die.speed = 0.2f;

	animation = &die;


	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




}

void Enemy_Land1::Move()
{

	position.y = original_y;
	
	if (going_right) {
		distance++;
		position.x++;
	}
	if (distance > 100 && going_right) {
		distance = 0;
		going_right = false;
	}
	if (!going_right) {
		distance++;
		position.x--;
	}
	if (distance > 100 && !going_right) {
		distance = 0;
		going_right = true;
	}

}

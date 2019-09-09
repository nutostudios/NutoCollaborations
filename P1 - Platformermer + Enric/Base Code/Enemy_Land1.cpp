#include "Application.h"
#include "Enemy_Land1.h"
#include "ModuleCollision.h"

Enemy_Land1::Enemy_Land1(int x, int y) : Enemy(x, y)
{
	//fly.PushBack({ 5,6,24,24 });
	//fly.PushBack({ 38, 6, 24, 24 });
	//fly.PushBack({ 71, 6, 24, 24 });
	//fly.PushBack({ 104, 6, 24, 24 });
	//fly.PushBack({ 137, 6, 24, 24 });
	//fly.PushBack({ 170, 6, 24, 24 });
	//fly.PushBack({ 203, 6, 24, 24 });
	//fly.PushBack({ 236, 6, 24, 24 });
	//fly.speed = 0.2f;

	//animation = &fly;

	//collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
	distance = 0;

	walk.PushBack({ 5,6,24,24 });
	walk.PushBack({ 236, 6, 24, 24 });
	walk.PushBack({ 236, 6, 24, 24 });
	walk.speed = 0.2f;

	animation = &walk;

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

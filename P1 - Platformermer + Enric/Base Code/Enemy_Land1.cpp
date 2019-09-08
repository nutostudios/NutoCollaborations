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


	walk.PushBack({ 5,6,24,24 });
	walk.PushBack({ 236, 6, 24, 24 });
	walk.PushBack({ 236, 6, 24, 24 });
	walk.speed = 0.2f;

	animation = &walk;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




}

void Enemy_Land1::Move()
{
	//if (going_up)
	//{
	//	if (wave > 1.0f)
	//		going_up = false;
	//	else
	//		wave += 0.05f;
	//}
	//else
	//{
	//	if (wave < -1.0f)
	//		going_up = true;
	//	else
	//		wave -= 0.05f;
	//}

	//position.y = int(float(original_y) + (25.0f * sinf(wave)));
	//position.x -= 1;

	position.y = original_y;
	position.x = original_x + walk_speed;
	if (distance > 100)
	{
		walk_speed = walk_speed * (-1);
		distance = 0;
	}
	else
	{
		distance += 1;
	}

	//if (walk_speed > 0)
	//{
	//	original_x += walk_speed;
	//}
	//else
	//{
	//	original_x -= walk_speed;
	//}
}

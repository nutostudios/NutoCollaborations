#include "Application.h"
#include "Enemy_Turret1.h"
#include "ModuleCollision.h"

Enemy_Turret1::Enemy_Turret1(int x, int y) : Enemy(x, y)
{

	original_y = y;
	original_x = x;

	//Idle
	idle.PushBack({ 236, 6, 24, 24 });
	idle.PushBack({ 236, 6, 24, 24 });
	idle.speed = 0.2f;

	animation = &idle;


	//Shooting
	shoot.PushBack({ 236, 6, 24, 24 });
	shoot.PushBack({ 236, 6, 24, 24 });
	shoot.speed = 0.2f;

	animation = &shoot;


	//Turret particle
	turret_particle.PushBack({ 236, 6, 24, 24 });
	turret_particle.PushBack({ 236, 6, 24, 24 });
	turret_particle.speed = 0.2f;

	animation = &turret_particle;


	//Die
	die.PushBack({ 236, 6, 24, 24 });
	die.PushBack({ 236, 6, 24, 24 });
	die.speed = 0.2f;

	animation = &die;

	//Collision turret itself
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	//Collision Particle




}

void Enemy_Turret1::Move()
{

	position.y = original_y;
	position.x = original_x;


}

void Enemy_Turret1::Shoot()
{



}

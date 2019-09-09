#include "Application.h"
#include "Enemy_Turret1.h"
#include "ModuleCollision.h"

#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"

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

	//int particle_distance = 0;

	//if (particle_distance > 100)
	//{
	//	App->particles->AddParticle(App->particles->laser, /*positionX*/1, /*positionY*/2, COLLIDER_ENEMY_SHOT);
	//}

	turret_shot = false;
}

void Enemy_Turret1::Move()
{
	if (original_x - App->player->positionX < 200 && !turret_shot) {
		App->particles->AddParticle(App->particles->laser, 400, 120, COLLIDER_ENEMY_SHOT);
		collider->rect.x++;
		turret_shot = true;
	}

}


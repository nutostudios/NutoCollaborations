#include "Application.h"
#include "PlatformBase.h"
#include "ModuleCollision.h"

#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"

Platform::Platform(int x, int y) : Enemy(x, y)
{

	//añadir variable con longitud, tipo, etc de plataforma
	original_y = y;
	original_x = x;

	//Idle
	idle.PushBack({ 236, 6, 24, 24 });
	idle.PushBack({ 236, 6, 24, 24 });
	idle.speed = 0.2f;

	animation = &idle;


	collider = App->collision->AddCollider({ 0, 0, 500, 25 }, COLLIDER_TYPE::COLLIDER_PLATFORM, (Module*)App->enemies);


}

void Platform::Move()
{

	position.y = original_y;
	position.x = original_x;

}
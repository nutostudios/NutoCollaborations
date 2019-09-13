#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleSceneSpace.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/background.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	// Colliders ---

	//				Suelo
	App->collision->AddCollider({0, 150, 3930, 16}, COLLIDER_WALL);
	//				Primera plataforma
	App->collision->AddCollider({ 200, 75, 1000, 16 }, COLLIDER_WALL);

	

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 600, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 625, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 640, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 665, 80);
	
	// TODO 1: Add a new wave of red birds

	//LAND1 ENEMIES ADD
	App->enemies->AddEnemy(ENEMY_TYPES::LAND1, 200, 20);
	
	//TURRET1 ENEMIES ADD
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET1, 400, 120);


	//PLATFORMS ADD
	/*App->enemies->AddEnemy(ENEMY_TYPES::PLATFORM, 300, 120);*/
	App->enemies->AddEnemy(ENEMY_TYPES::PLATFORM, 300, 120);


	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	//App->render->camera.x += 1 * SCREEN_SIZE;




	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}
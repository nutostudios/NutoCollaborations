#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleSceneSpace.h"


ModulePlayer::ModulePlayer()
{
	// idle animation (just the ship)
	idle.PushBack({   0, 0, 23, 28 });
	idle.PushBack({  23, 0, 23, 28 });
	idle.PushBack({  46, 0, 23, 28 });
	idle.PushBack({  69, 0, 23, 28 });
	idle.speed = 0.2f;

	// move upwards
	jump.PushBack({ 92, 0, 23, 28});

	// Move down
	down.PushBack({33, 1, 32, 32});
	down.PushBack({0, 1, 32, 32});
	down.loop = false;
	down.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/Ninja_Frog.png");

	destroyed = false;
	position.x = 0;
	position.y = -100;
	velocity.x = 0;
	velocity.y = 0;


	playerWidth = 23;
	playerHeight = 28;


	feet.w = playerWidth;
	feet.h = 1;

	col = App->collision->AddCollider({ 0, 120, playerWidth, playerHeight }, COLLIDER_PLAYER, this);
	colFeet = App->collision->AddCollider(feet, COLLIDER_PLAYER, this);

	grounded = false;
	againstRightWall = false;
	againstLeftWall = false;

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	destroyed = true;
	if (col != nullptr)	col->to_delete = true;

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	float speed = 1;
	position.x -= velocity.x;
	position.y -= velocity.y;
	feet.x = position.x;
	feet.y = position.y + playerHeight;

	if (!grounded)
		current_animation = &jump;
	else
		current_animation = &idle;

	/*for (int i = 0; i < 3; i++) {
		if (App->scene_space->col[i]->CheckCollision(feet)) {
			grounded = true;
			break;
		}
		else {
			grounded = false;
		}
	}*/

	App->render->camera.x = position.x;
	App->render->camera.y = position.y - 100;

	if(!grounded || S_Down) velocity.y -= 0.1;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) {
		if (!againstLeftWall) velocity.x = 2 * speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP) velocity.x = 0;


	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) {
		if (!againstRightWall) velocity.x = (-2) * speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP) velocity.x = 0;


	if (App->input->keyboard[SDL_SCANCODE_H] == KEY_STATE::KEY_DOWN) {
		position.y = 0;
		grounded = false;;
	}


	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN  && grounded) {
		grounded = false;
		velocity.y = 4 * speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN) {
		S_Down = true;
		grounded = false;
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP) S_Down = false;

	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)	App->particles->AddParticle(App->particles->shuriken, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);

	//col->rect.x = position.x;
	//col->rect.y = position.y;
	colFeet->rect = feet;

	// Draw everything --------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//if(destroyed == false)
	if (current_animation == &idle) App->render->Blit(graphics, position.x, position.y, &idle.GetCurrentFrame());
	else if (current_animation == &jump) App->render->Blit(graphics, position.x, position.y, &jump.GetCurrentFrame());
		

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) //TREAT C1 AS THE PLAYER	
{
	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_WALL && velocity.y < 0) {					//FLOOR COLLISION
		velocity.y = 0;
		position.y = c2->rect.y - playerHeight;
		grounded = true;
	}
	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_PLATFORM && velocity.y < 0 && !S_Down && (				//PLATFORM VERTICAL COLLISION
		position.y + playerHeight) < c2->rect.y + 5) {
		velocity.y = 0;
		position.y = c2->rect.y - playerHeight;
		grounded = true;
	}
}

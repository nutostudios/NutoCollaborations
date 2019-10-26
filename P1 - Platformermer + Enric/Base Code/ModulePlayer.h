#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

private:
	SDL_Texture* graphics = nullptr;

public:

	Animation* current_animation = nullptr;
	Animation idle;
	Animation jump;
	Animation down;


	fPoint position;
	SDL_Rect feet;
	fPoint desiredPosition;
	fPoint velocity;


	int playerHeight;
	int playerWidth;

	bool S_Down = false;

	bool grounded;
	bool againstRightWall;
	bool againstLeftWall;


	Collider* col;
	Collider* colFeet;

	bool destroyed;

	
	bool jumping;
};

#endif
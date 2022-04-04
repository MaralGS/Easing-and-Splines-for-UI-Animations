#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Animation.h"
#include "Point.h"
#include "EasingFunctions.h"
#include <vector>

//class GuiControl;

struct SDL_Texture;
struct Example 
{
	iPoint Position;
};
class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	float EaseRectangleBetweenPoints(iPoint posA, iPoint posB);

private:
	SDL_Texture* img;
	SDL_Rect Exemple;
	Example Ej;

	iPoint pointA;
	iPoint pointB;

	int iterations;
	int total_iterations;
	bool easing_active;
	//TODO1: Implement the EasingFunction class

};

#endif // __SCENE_H__
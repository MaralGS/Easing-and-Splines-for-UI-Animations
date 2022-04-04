#include "App.h"
#include "Input.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "Map.h"
#include "EasingFunctions.h"

#include "Defs.h"
#include "Log.h"

Scene::Scene() : Module()
{
	name.Create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	Ej.Position.x = 100;
	Ej.Position.y = 100;
	//TODO2: Determine the inital and the final point
	

	//TODO2: Determine the time of the animation (Remeber is the dt * the time you want your animation)
	



	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
   
	if(app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		app->LoadGameRequest();

	if(app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		app->SaveGameRequest();

	if (app->input->GetKey(SDL_SCANCODE_9) == KEY_DOWN) {
		
		Ej.Position.x = 100;
		//TODO3 Set the inital time to 0

		easing_active = true;
	}

	if (easing_active == true) {
		//TODO3: Add to the position of the player the funcion of the easing
	}

	Exemple = {Ej.Position.x,Ej.Position.y, 100, 100};
	app->render->DrawRectangle(Exemple, 200, 200, 200);


	// Draw map
	app->map->Draw();
	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

float Scene::EaseRectangleBetweenPoints(iPoint posA, iPoint posB) {

	//TODO4: Create a float variable and equal it to the easing funcion you want to use
	

	
	//TODO4 Make an if that adds one to te inital time until it reaches the final time and when it arrives deactivates the easing and sets the inital time to 0
	


	//TODO5: Return the value of the variable
	return;
}


// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}

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
	pointA = { 100,100 };
	pointB = { 500,100 };
	

	total_iterations = 60;

	speedX = 0;

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
    // L02: DONE 3: Request Load / Save when pressing L/S
	if(app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		app->LoadGameRequest();

	if(app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		app->SaveGameRequest();

	if (app->input->GetKey(SDL_SCANCODE_9) == KEY_DOWN) {
		Ej.Position.x = 100;
		iterations = 0;
		easing_active = true;
	}

	if (easing_active == true)
		Ej.Position.x += EaseRectangleBetweenPoints(pointA, pointB) * 0.05;

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
	float value = Efunction.circEaseIn(iterations, posA.x, posB.x - posA.x, total_iterations);


	//speedY = function.linearEaseNull(iterations, 472, 572, 300);

	//App->render->camera.y += speedY;

	if (iterations < total_iterations) {
		iterations++;
	}

	else {
		iterations = 0;
		easing_active = false;
	}

	return value;
}


// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}

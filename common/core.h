#ifndef CORE_H 
#define CORE_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>
#include <common/inputmanager.h>

class Core 
{ 
public: 
    Core(); 
    virtual ~Core();

	void Run(Scene* scene);

	bool IsRunning() { return running; }

private:
	Renderer renderer;

	void UpdateEntity(Entity* e, float deltaTime);

	InputManager* _inMan = InputManager::input();
	bool running;
}; 

#endif
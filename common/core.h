#ifndef CORE_H 
#define CORE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>

class Core 
{ 
public: 
    Core();
    virtual ~Core();

	void Run(Scene* scene);

	bool IsRunning() { return running; }

private:
	Renderer renderer;
	bool running;
}; 

#endif
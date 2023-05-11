#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>

#include "gamescene.h"

int main( void )
{
	Renderer renderer;

	GameScene* scene = new GameScene();

	do 
	{
		// get deltaTime and update camera
		float dt = renderer.updateDeltaTime();
		scene->camera()->computeViewMatrixFromInput(renderer.window(), dt);

		// Update the scene
		scene->update(dt); //(and make Scene abstract?)

		// Render the scene
		renderer.renderScene(scene);
	} 
	// Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete scene;

	return 0;
}
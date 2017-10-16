#include <string>
#include <GL\glew.h>
#include <SDL.h>
#include "Application.h"
#include "Log.h"

void Thing::Application::initWindow(const std::string title, const int windowWidth, const int windowHeight)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (!window)
		{
			THING_LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			if (SDL_GL_CreateContext(window))
			{
				GLenum glewError = glewInit();
				if (glewError != GLEW_OK)
				{
					THING_LOG("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
				}

				//disable Vsync
				//SDL_GL_SetSwapInterval(0);

				//Initialize OpenGL
				//if (!initGL())
				//{
				//	printf("Unable to initialize OpenGL!\n");
				//}

				update();

			}
		}
	}
	else
	{
		THING_LOG("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
}

void Thing::Application::update()
{
	bool quit = false;
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//Handle keypress with current mouse position
			//else if (e.type == SDL_TEXTINPUT)
			//{
			//	int x = 0, y = 0;
			//	SDL_GetMouseState(&x, &y);
				//handleKeys(e.text.text[0], x, y);
			//}
		}

		//update();

		glClear(GL_COLOR_BUFFER_BIT);

		//Update screen
		SDL_GL_SwapWindow(window);
	}
}

Thing::Application::~Application()
{
	if (window)
	{
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}
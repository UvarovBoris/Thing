#pragma once

#include <string>

struct SDL_Window;

namespace Thing
{
	

	class Application
	{
		SDL_Window* window;
		
		void update();

	public:
		Application() : window(nullptr)
		{
		}

		void initWindow(const std::string title, const int windowWidth, const int windowHeight);

		~Application();

	};
}
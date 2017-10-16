#include <iostream>
#include "Application.h"

int main(int argc, char* argv[])
{
	Thing::Application application;
	application.initWindow("Thing demo", 1280, 720);

	return 0;
}
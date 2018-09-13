#include <GLFW\glfw3.h>
#include <iostream>

#include "src\window.h"

int main()
{
	using namespace engine;
	using namespace graphics;
	Window window("main", 800, 600);
	while (!window.closed()) 
	{
		window.clear();
		window.update();
	}
	std::cin.get();
	return 0;
}
#include "Game.h"
#include <iostream>

int main()
{
	Game g;

	std::cout << "Initial game state: \n" << g << std::endl;
	g.solve2();

	return 0;
}

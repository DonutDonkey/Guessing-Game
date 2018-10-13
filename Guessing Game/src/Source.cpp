#include "..\include\System.h"

#include <iostream>

int main() {
	auto quit = NULL;
	System system;

	system.Launch();

	while (!quit)
	{
		(system.main_game()) ? quit = true : quit;
	}

	return 0;
}
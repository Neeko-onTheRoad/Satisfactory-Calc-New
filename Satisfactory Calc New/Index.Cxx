#include <ctime>
#include <iostream>
#include <Windows.h>

#include "EmptyScene.Hxx"
#include "ConsoleWindow.Hxx"

int main(int argv, char* argc[]) {


	ConsoleWindow window = ConsoleWindow();

	for (int i = 0; i < argv; i++) {
		if (argc[i] == "--help") {
			printf("--help: print commands\n");
			printf("--potato-mode: run console with slow thread");
		}

		if (argc[i] == "--potato-mode") {
			window.PotatoMode = true;
		}
	}

	window.Initialize();
	window.Run();

}	
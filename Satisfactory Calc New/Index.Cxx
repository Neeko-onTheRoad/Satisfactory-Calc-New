#include <ctime>
#include <iostream>
#include <Windows.h>

#include "EmptyScene.Hxx"
#include "ConsoleWindow.Hxx"

int main(void) {
	
	ConsoleWindow window = ConsoleWindow();
	window.Initialize(new EmptyScene());
	window.Run();

}
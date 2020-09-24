#include <stdio.h>
#include "ProgramMenu.h"

int main() {
	ProgramMenu *prog = ProgramMenu::getInstance();
	prog->printWelcomeScreen();
	prog->selectOption();

	return 0;
}

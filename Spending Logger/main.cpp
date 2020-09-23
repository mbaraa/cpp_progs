#include <stdio.h>
#include "ProgramMenu.h"

int main() {

	ProgramMenu *m = new ProgramMenu(); 
	
	m->printWelcomeScreen();
	m->selectOption();

	return 0;
	
}

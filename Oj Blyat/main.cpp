#include <stdio.h>
#include "Menu.h"

int main() {
	
	Menu *m = new Menu(); 

	m->addOption("OJ");
	m->addOption("Cyka");
	m->addOption("LOL");
	m->addOption("BLYAT");
	m->addOption("FOO");

	
	while(1) {
		
		int v;
		v = m->chooseOption();
		printf("choice: %d\n", v);
	
	}

	return 0;
	
}

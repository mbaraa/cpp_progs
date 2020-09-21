#include <stdio.h>
#include "ProgramMenu.h"

int main() {

/*	json j = json();
	JsonFile *jf = new JsonFile(&j, "bebo");

	jf->load();
	j["9/21/2020"]["bananas"]["price"]  = 3;
	jf->append();
	jf->load();

	jf->del();
	delete jf;
	jf = new JsonFile(&j, "bebo");
	jf->append();

	std::cout << j << endl;

	return 0;	
	*/ProgramMenu *m = new ProgramMenu(); 
	
	//m->printWelcomeScreen();
	m->selectOption();

	return 0;
	
}

#include <iostream>
#include <unistd.h> /* this is the name of the header file that provides access to the POSIX \
operating system API. It is defined by the POSIX.1 standard, the base of the Single Unix Specification,\
and should therefore be available in any conforming (or quasi-conforming) \
operating system/compiler (all official versions of UNIX, including macOS, Linux, etc.).
*/
/* if using windows use this header 
#include <windows.h>
*/
using namespace std;
int main(){
	int x;
	cin >> x;
	usleep(3000000);// this will wait 3 million micro seconds (3 seconds) then executes the next statement
	/* if using windows 
	Sleep(3000); // Note uppercase S , and time in milliseconds hence this is 3000 milliseconds
	*/
	cout << x;
	return 0 ;\

}


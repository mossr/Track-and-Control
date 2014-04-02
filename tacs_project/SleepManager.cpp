#include <set>
#include <iostream>
#include <windows.h>

using namespace std;
	
const int resolutionX = GetSystemMetrics(SM_CXSCREEN); //Screen Resulution x
const int resolutionY = GetSystemMetrics(SM_CYSCREEN); //Screen Resulution y

//Will determine if the user has left the field of view and will put the computer to sleep.
void putTosleep()//POINT pos)
{
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
}

int main() 
{ 
	int x = 0, y = 0;
	POINT tracker; //This point will be generated from the position of the user.

	while(1)
	{
		GetCursorPos(&tracker);

		if(!((tracker.x > 1 && tracker.x < resolutionX - 1)	&&	(tracker.y > 1 && tracker.y < resolutionY - 1)))
		{
			putTosleep();
			SetCursorPos(resolutionX/2, resolutionY/2);
		}
	}
}
#include <iostream>
#include <stdio.h>
#include <opencv\cv.h>
#include <Windows.h>

#include "Tracker.h"
#include "FacialRecognitionTracker.h"
#include "ObjectTracker.h"
#include "MouseTracker.h"

#include "WindowsGridOrganizer.h"

using namespace std;
using namespace cv;

void getFeed();
void feature_wgo(int x, int y);
void feature_wgo_reset();

int hotkey = VK_LCONTROL;

int main( int argc, const char** argv )
{
	setGrid();
	getFeed();
}

void getFeed()
{
	// 1 = ObjectTracker
	// 2 = FacialRecognitionTracker
	// 3 = MouseTracker
	int tracker = 1;
	while(true)
	{

		Point xy;
		switch(tracker){
		case 1:
			xy = track_ot();
			break;
		case 2:
			xy = track_frt();
			break;
		case 3:
			xy = track_mt();
			break;
		}
		std::cout << xy << std::endl;

		
		if(GetAsyncKeyState(hotkey)){
			feature_wgo(xy.x, xy.y);
		}
		else
		{
			feature_wgo_reset();
		}
	}
}

void feature_wgo(int x, int y)
{
	setMiddle(x, y);
}

void feature_wgo_reset()
{
	resetMiddle();
}
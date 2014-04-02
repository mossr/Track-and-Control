
#include <sstream>
#include <string>
#include <iostream>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <Windows.h>

using namespace cv;
using namespace std;


//default capture width and height
const int FRAME_WIDTH = 640;
const int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
const double RATIO_WIDTH = (double) SCREEN_WIDTH / (double) FRAME_WIDTH;
const int FRAME_HEIGHT = 480;
const int SCREEN_HEIGHT =  GetSystemMetrics(SM_CYSCREEN);

int _x = -1;
int _y = -1;
LPCSTR left_window_name = "WIT";
LPCSTR right_window_name = "Documents";
LPCSTR top_window_name = "top.txt - Notepad";
LPCSTR bottom_window_name = "cmd - tacs";
LPCSTR middle_window_name = "middle.txt - Notepad";
HWND left_window = FindWindow(NULL, TEXT(left_window_name));
HWND right_window = FindWindow(NULL, TEXT(right_window_name));
HWND top_window = FindWindow(NULL, TEXT(top_window_name));
HWND bottom_window = FindWindow(NULL, TEXT(bottom_window_name));
HWND middle_window = FindWindow(NULL, TEXT(middle_window_name));
double y_speed = 2.0;
double x_speed = 2.0;
double width_ratio = (1/10);
double height_ratio = (1/5);
double window_width = 300;
double window_height = 300;

RECT getWindowRect(LPCSTR window) {
	// Gets the window handler by name
	HWND handler = FindWindow(NULL, TEXT(window));
	// Pointer to rect from the window
	RECT rect;
	// Gets the left-x, top-y, right-x, and bottom-y coordinates of the window
	GetWindowRect(handler, &rect);
	return rect;
}

int ratioHeight(RECT rect, double ratio) {	
	LONG ty = rect.top;
	LONG by = rect.bottom;
	cout << ty << "," << by << endl;

	int height_current = abs(ty - by);
	int height_new = height_current * ratio;
	return height_new;
}

int ratioWidth(RECT rect, double ratio) {
	LONG lx = rect.left;
	LONG rx = rect.right;
	cout << lx << "," << rx << endl;

	int width_current = abs(lx - rx);
	int width_new = width_current * ratio;
	return width_new;
}

HWND getLeft() {
	return left_window;
}

void setLeft(LPCSTR window) {
	RECT rect = getWindowRect(window);
	int width = window_width; //ratioWidth(rect, width_ratio);
	int height = SCREEN_HEIGHT;

	SetWindowPos(left_window, HWND_TOPMOST, 0, 0, width, height, 0);
}

void setRight(LPCSTR window) {
	RECT rect = getWindowRect(window);
	int width = window_width; //ratioWidth(rect, width_ratio);
	int height = SCREEN_HEIGHT;

	SetWindowPos(right_window, HWND_TOPMOST, SCREEN_WIDTH - width, 0, width, height, 0);
}

void setTop(LPCSTR window) {
	RECT rect = getWindowRect(window); 
	int width = SCREEN_WIDTH - (window_width*2);
	int height = window_height; //ratioHeight(rect, height_ratio);

	SetWindowPos(top_window, HWND_TOPMOST, window_width, 0, width, height, 0);
}

void setBottom(LPCSTR window) { 
	RECT rect = getWindowRect(window);
	int width = SCREEN_WIDTH - (window_width*2);
	int height = window_height; //ratioHeight(rect, height_ratio);

	SetWindowPos(bottom_window, HWND_TOPMOST, window_width, SCREEN_HEIGHT - height, width, height, 0);
}

void setMiddle(int x, int y) {
	HDESK desktop = NULL;

	//EnumWindows(EnumWindowsProc, NULL);

	//Updates the tracked position as the center.
	if(_x < 0)
		_x = x;
	if(_y < 0)	
		_y = y;

	//	moveWindow(windowName, x * RATIO_WIDTH, y);

	//Find window by handle name (also see EnumDesktopWindows())
	int x_update = RATIO_WIDTH * (x - _x);
	int y_update = -(y - _y);

	if(abs(x_update) > abs(y_update)){
		x_update *= x_speed;
		y_update = 0;
		SetWindowPos(left_window, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		SetWindowPos(right_window, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
	else{
		x_update = 0;
		y_update *= y_speed;
		SetWindowPos(top_window, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		SetWindowPos(bottom_window, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
	SetWindowPos(middle_window, HWND_TOP, x_update, y_update, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_SHOWWINDOW);
	return;
	
	//x = -1;
	//y = -1;

//	SetWindowPos(middle_window, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE);
}

void resetMiddle()
{
	SetWindowPos(middle_window, HWND_TOP, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_SHOWWINDOW);
}

void setGrid() {
	setLeft(left_window_name);
	setRight(right_window_name);
	setBottom(bottom_window_name);
	setTop(top_window_name);
}
#include "windowMain.h"

#define WNDCLASSNAME "wndclass"
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1200

#define WINDOW_START_X 100
#define WINDOW_START_Y 100

HDC hdc;
HWND hwnd;

bool quit = false;

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:
	{
					 PostQuitMessage(0);
					 break;
	}
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

int WINAPI WinMain(HINSTANCE hinstance,
	HINSTANCE hprevinstance,
	LPSTR lpcmdline,
	int nshowcmd)
{

	MSG msg;
	WNDCLASSEX ex;

	ex.cbSize = sizeof(WNDCLASSEX);
	ex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	ex.lpfnWndProc = WinProc;
	ex.cbClsExtra = 0;
	ex.cbWndExtra = 0;
	ex.hInstance = hinstance;
	ex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	ex.hCursor = LoadCursor(NULL, IDC_ARROW);
	ex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	ex.lpszMenuName = NULL;
	ex.lpszClassName = WNDCLASSNAME;
	ex.hIconSm = NULL;

	RegisterClassEx(&ex);

	// Create the window 

	hwnd = CreateWindowEx(NULL,
		WNDCLASSNAME,
		"Window",
		WS_OVERLAPPEDWINDOW,
		WINDOW_START_X, WINDOW_START_Y,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		NULL,
		NULL,
		hinstance,
		NULL);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	// The message loop 

	while (!quit)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				quit = true;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.lParam;
}

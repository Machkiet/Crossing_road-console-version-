#include "Header.h"

Console::Console()
{
	width = 120; height = 40;
	// thay đổi kích thước
	SetWindowSize();
	SetScreenBufferSize();

	//khóa phóng to thu nhỏ
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);

	// khóa botton
	HWND hWnd2 = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd2, false);
	DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);

	setBackgroundColor(2);
	Nocursortype();
}


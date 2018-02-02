#include <ND_Panic.hpp>
#include <ND_Screen.hpp>

void ND::Panic::Show(const char* error)
{
	ND::Screen::Clear(ND_COLOR_RED);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND, ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND, ND_COLOR_RED);
	ND::Screen::SetCursor(29,10); //(80-22)/2
	ND::Screen::PutString("Lorena Kernel Error\n");
	ND::Screen::SetCursor(15,12);
	ND::Screen::PutString(error);
}

#include <ND_Screen.hpp>
#include <ND_Keyboard.hpp>
#include "NextShellLite.hpp"
#include <ND_String.hpp>

char DIVISION_EXCEPTION[]={};

void Version()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("Lorena 0.4.1 - LorenaShell 0.2.0\n");
}
void Echo()
{
	char* str=ND::Keyboard::GetString();
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString(str);
}
void Help()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_CYAN);
	ND::Screen::PutString("\nBienvenido a Lorena!\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_MAGENTA);
	ND::Screen::PutString("\n");
	ND::Screen::PutString("Sobre el sistema:\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Lorena es un sistema operativo escrito en C, C++, Ensablador basado en NextDivel.\n");
	ND::Screen::PutString("Lorena es desarrollado actualmente por su creador. Este es su cuarto lanzamiento.\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_MAGENTA);
	ND::Screen::PutString("Comandos:\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("echo: Imprime el eco de un texto en la pantalla.\n");
	ND::Screen::PutString("clear: Limpia la pantalla.\n");
	ND::Screen::PutString("version: Muestra la version del sistema.\n");
}
void Clear()
{
	ND::Screen::Clear(ND_COLOR_BLACK);
}

void NextShell::Lite::Keys::Help()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_MAGENTA);
	ND::Screen::PutString("\n");
	ND::Screen::PutString("Sobre el sistema:\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Lorena es un sistema operativo escrito en C, C++, Ensablador basado en NextDivel.\n");
	ND::Screen::PutString("Lorena es desarrollado actualmente por su creador. Este es su cuarto lanzamiento.\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_MAGENTA);
	ND::Screen::PutString("Comandos:\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("echo: Imprime el eco de un texto en la pantalla.\n");
	ND::Screen::PutString("clear: Limpia la pantalla.\n");
	ND::Screen::PutString("version: Muestra la version del sistema.\n");
	ND::Screen::PutString("Por favor visite https://github.com/Alvarito050506/Lorena/ y contribuya al proyecto!\n");
}

void NextShell::Lite::Keys::Reboot()
{
	// Aún no implementado (sin ideas)
}

void NextShell::Lite::Commands::NotFound()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
	ND::Screen::PutString("\nNo se pudo encontrar el comando.\n");
}


int NextShell::Lite::ExecuteString(char* script)
{
	if( ND::String::Compare("echo\n",script)==0 ) {
		NextShell::Lite:Commands::Echo();
	} else if( ND::String::Compare("clear\n",script)==0 ) {
		NextShell::Lite::Commands::Clear();
   	} else {
		if(ND::String::Compare("version\n",script)==0 )
		{
			NextShell::Lite::Commands::Version();
		} else if(ND::String::Compare("H\n",script)==0) {
			NextShell::Lite::Keys::Help();
		} else {
			NextShell::Lite::Commands::NotFound();
		}
	}
	NextShell::Lite::WaitForCommand();
}
int NextShell::Lite::WaitForCommand()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Shell$ ");
	char* cmd=ND::Keyboard::GetString();
	//ND::Screen::PutString(cmd);
	NextShell::Lite::ExecuteString(cmd);
	
}
int NextShell::Lite::main()
{
	ND::Screen::Clear(ND_COLOR_BLACK);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Password: ");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	char* password=ND::Keyboard::GetString();
	if(ND::String::Compare("12345678\n",password)==0)
	{
		NextShell::Lite:Commands::Clear();
		ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLUE);
		ND::Screen::PutString("Lorena v0.4.1\n");
		NextShell::Lite:Commands::Help();
		NextShell::Lite::WaitForCommand();
	}
	else
	{
		ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
		ND::Screen::PutString("Password incorrecto. Reinicie el equipo e intentelo de nuevo.\n");
	}
}

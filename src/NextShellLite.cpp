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
	ND::Screen::PutString("Lorena es un sistema operativo escrito en C, C++, Ensablador y Bash basado en NextDivel.\n");
	ND::Screen::PutString("Lorena es desarrollado actualmente, este es su tercer lanzamiento.\n");
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


void NextShell::Lite::Commands::ForceException()
{
	void (*f)(void) = (void (*)(void)) DIVISION_EXCEPTION;
	f();
}
void NextShell::Lite::Commands::NotFound()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
	ND::Screen::PutString("\nNo se pudo encontrar el comando\n");
}

void BasicExecuteString(char* bas)
{
	if( ND::String::Compare("echo\n",bas)==0 ) {
		Echo();
   	} else if( ND::String::Compare("exit\n",bas)==0 ) {
		NextShell::Lite::main();
  	} else {
      		NextShell::Lite::Commands::NotFound();
   	}
}
int BasicWaitForCommand()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Basic:> ");
	char* basscript=ND::Keyboard::GetString();
	//ND::Screen::PutString(basscript);
	BasicExecuteString(basscript);
	
}




int NextShell::Lite::ExecuteString(char* script)
{
	if( ND::String::Compare("echo\n",script)==0 ) {
		Echo();
   	} else if( ND::String::Compare("version\n",script)==0 ) {
		Version();
	} else if( ND::String::Compare("clear\n",script)==0 ) {
		Clear();
   	} else {
      		NextShell::Lite::Commands::NotFound();
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
//	ND::Screen::Clear(ND_COLOR_BLACK);
//	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
//	ND::Screen::PutString("Password: ");
//	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
//	char* password=ND::Keyboard::GetString();
//	if(ND::String::Compare("12345678\n",password)==0)
//	{
		Clear();
		ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLUE);
		ND::Screen::PutString("Lorena v0.3.0\n");
		Help();
		NextShell::Lite::WaitForCommand();
//	}
//	else
//	{
//		ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
//		ND::Screen::PutString("Password incorrecto. Reinicie el equipo e intentelo de nuevo.\n");
//	}
}

//BAS: echo, exit
//CALC: sumar, restar

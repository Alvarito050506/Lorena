 /* Check if the compiler thinks if we are targeting the wrong operating system. */
#ifndef NEXT_DIVEL
#endif
#include "ND_Screen.hpp"
#include "ND_Color.hpp"
#include "ND_Panic.hpp"
#include "ND_Keyboard.hpp"
#include "ND_GDT.hpp"
#include "ND_IDT.hpp"
#include "ND_IRQ.hpp"
#include "ND_Timer.hpp"
#include "NextShellLite.hpp"

//#include "NextKernel_GDT.h"
//#include "NextDivel.h"
//#include <ND_Multiboot.hpp>
//#include "NextFS.h"
//#include "ND_Initrd.h"
//extern uint32_t placement_address;
//extern fs_node_t* fs_root;
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
int NextKernel_Main(/*struct multiboot *mboot_ptr*/)
{
	asm volatile("cli");
	ND::Screen::Clear(ND_COLOR_BLACK);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND,ND_COLOR_BLACK);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLUE);
	ND::Screen::PutString("Lorena\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Licenciado bajo GNU GPL v3\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Configurando el sistema...");
	ND::GDT::Install();
	ND::IDT::Install();
	ND::IRQ::Install();
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString(" Echo.");


	ND::Keyboard::Setup();
	ND::Timer::Setup();
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Configurando entradas USB...");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
	ND::Screen::PutString(" FALLIDO!\n");



	ND::Timer::Phase(50);

	asm volatile("sti");
	ND::Keyboard::wait();

	ND::Timer::Wait(100);

	NextShell::Lite::main();

	while(1)
	{
	
	}

	return 0;
}

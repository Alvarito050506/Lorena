namespace ND{
	namespace Timer{
			void Setup();
			void Phase(int hz);
			void Wait(int ticks);
		}
}
extern "C"
void ND_Timer_Handler(struct regs* r);


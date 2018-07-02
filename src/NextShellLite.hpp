#ifndef NEXTSHELLLITE_HPP
#define NEXTSHELLLITE_HPP

namespace NextShell{
	namespace Lite{
		int main();
		int WaitForCommand();
		int ExecuteString(char* script);
		namespace Keys{
			void Help();
			void Reboot();
		}
		namespace Commands{
			void Echo();
			void Clear();
			void Version();
			void NotFound();
		}
	}
}

#endif

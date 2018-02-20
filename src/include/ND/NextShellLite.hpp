#ifndef NEXTSHELLLITE_HPP
#define NEXTSHELLLITE_HPP

namespace NextShell{
	namespace Lite{
		int main();
		int WaitForCommand();
		int ExecuteString(char* script);
		namespace Commands{
			void Version();
			void ForceException();
			void NotFound();
		}
	}
}

#endif

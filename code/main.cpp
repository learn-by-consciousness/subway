#include "subway.h"
#include "memu.h"

int main()
{
	subway_system system;
	Memu memu;
	while(memu.isChecking())
	{
		memu.printMemu();
		string origin = memu.getOrigin();
		string destination = memu.getDestination();
		if(system.isStaition(origin) && system.isStaition(destination))
			system.checkLine(origin, destination);
	}
	return 0;
}

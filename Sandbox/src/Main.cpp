#include "EntryPoint.h"

int main(const int argc, char** argv)
{
	if (argc == 1)
	{
		Gear::Main();
	}

	if (argc > 1)
	{
		Gear::Main(argc, argv);
	}
}
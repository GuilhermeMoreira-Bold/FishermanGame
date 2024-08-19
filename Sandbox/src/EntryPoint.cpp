#include "EntryPoint.h"

#include "Sandbox.h"

namespace Gear
{
	void Main()
	{
		FishmanLife::Sandbox sandbox;
		Application::SetInstance(&sandbox);
		Application::Init();
		Application::Run();
	}

	void Main(int argc, char** argv)
	{
		FishmanLife::Sandbox sandbox;
		Application::SetInstance(&sandbox);
		Application::Init();
		Application::Run();
	}
}

#include "Precompiled.h" // this is the god header, use it always
#include "App.h"

using namespace ProtoEngine;

void App::Run(const AppConfig& config)
{
	LOG("App Started");

	// initialize all singletons
	Window ourWindow;
	ourWindow.Initialize(GetModuleHandle(nullptr), config.appName, config.winWidth, config.winHeight);

	// initialize starting state

	// updates
	mIsRunning = true;
	while (mIsRunning)
	{
		ourWindow.ProcessMessage();
		if (!ourWindow.IsActive())
		{
			Quit();
			continue;
		}
		// updating all that needs updates
	}

	LOG("App Is Terminating");
	// terminate last state

	// terminate all singletons and window
	ourWindow.Terminate();

}

void App::Quit()
{
	mIsRunning = false;
}
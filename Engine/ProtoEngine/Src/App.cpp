#include "Precompiled.h" // this is the god header, use it always
#include "App.h"
#include "AppState.h"

using namespace ProtoEngine;
using namespace ProtoEngine::Core;
using namespace ProtoEngine::Graphics;

void App::Run(const AppConfig& config)
{
	LOG("App Started");

	// initialize all singletons
	Window ourWindow;
	ourWindow.Initialize(GetModuleHandle(nullptr), config.appName, config.winWidth, config.winHeight);
	auto handle = ourWindow.GetWindowHandle();
	GraphicsSystem::StaticInitialize(handle, false);

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
	GraphicsSystem::StaticTerminate();
	ourWindow.Terminate();

}

void App::Quit()
{
	mIsRunning = false;
}

void App::ChangeState(const std::string& stateName)
{
	auto iter = mAppStates.find(stateName);
	if (iter != mAppStates.end())
	{
		mNextState = iter->second.get();
	}
}
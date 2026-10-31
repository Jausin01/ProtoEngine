#include "Precompiled.h" // this is the god header, use it always
#include "App.h"
#include "AppState.h"

using namespace ProtoEngine;
using namespace ProtoEngine::Core;
using namespace ProtoEngine::Graphics;
using namespace ProtoEngine::Input;

void App::Run(const AppConfig& config)
{
	LOG("App Started");

	// initialize all singletons
	Window ourWindow;
	ourWindow.Initialize(GetModuleHandle(nullptr), config.appName, config.winWidth, config.winHeight);
	auto handle = ourWindow.GetWindowHandle();
	GraphicsSystem::StaticInitialize(handle, false);
	InputSystem::StaticInitialize(handle);

	// initialize starting state
	ASSERT(mCurrentState != nullptr, "App: no state is set");
	mCurrentState->Initialize();

	InputSystem* input = InputSystem::Get();
	// updates
	mIsRunning = true;
	while (mIsRunning)
	{

		ourWindow.ProcessMessage();
		input->Update();
		if (!ourWindow.IsActive() || input->IsKeyPressed(KeyCode::ESCAPE))
		{
			Quit();
			continue;
		}
		// updating all that needs updates

		if (mNextState != nullptr)
		{
			mCurrentState->Terminate();
			mCurrentState = std::exchange(mNextState, nullptr);
			mCurrentState->Initialize();
		}

		float deltaTime = TimeUtil::GetDeltaTime();
#if defined(_DEBUG)

		if (deltaTime > 0.5f)
		{
			continue;
		}

#endif // (DEBUG)

		mCurrentState->Update(deltaTime);

		GraphicsSystem* gs = GraphicsSystem::Get();
		gs->BeginRender();
		mCurrentState->Render();
		mCurrentState->DebugUI();
		gs->EndRender();
	}

	LOG("App Is Terminating");
	// terminate last state
	mCurrentState->Terminate();

	// terminate all singletons and window
	InputSystem::StaticTerminate();
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
#include <ProtoEngine/Inc/ProtoEngine.h>
#include "GameState.h"
#include "MainState.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	ProtoEngine::AppConfig config;
	config.appName = L"Hello App State";

	ProtoEngine::App& ourApp = ProtoEngine::MainApp();
	ourApp.AddState<MainState>("MainState");
	ourApp.AddState<GameState>("GameState");
	ourApp.Run(config);

	return 0;
}
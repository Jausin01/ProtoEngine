#include <ProtoEngine/Inc/ProtoEngine.h>
#include "DoSomethingState.h"
#include "Docolor.h"

int WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	ProtoEngine::AppConfig config;
	config.appName = L"Hello Shapes";

	ProtoEngine::App& ourApp = ProtoEngine::MainApp();
	ourApp.AddState<DoSomethingState>("DoSomethingState");
	ourApp.AddState<DoColor>("DoColorState");
	ourApp.Run(config);

	return 0;
}
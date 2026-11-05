#include <ProtoEngine/Inc/ProtoEngine.h>
#include "DoSomethingState.h"
#include "Docolor.h"
#include "DoColor2.h"
#include "DoColor3.h"


int WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	ProtoEngine::AppConfig config;
	config.appName = L"Hello Shapes";

	ProtoEngine::App& ourApp = ProtoEngine::MainApp();
	ourApp.AddState<DoSomethingState>("DoSomethingState");
	ourApp.AddState<DoColor>("DoColorState");
	ourApp.AddState<DoColor2>("DoColorState2");
	ourApp.AddState<DoColor3>("DoColorState3");
	ourApp.Run(config);

	return 0;
}
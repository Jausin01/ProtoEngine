#include <ProtoEngine/Inc/ProtoEngine.h>
#include "Docolor.h"



int WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	ProtoEngine::AppConfig config;
	config.appName = L"Hello Mesh Builder";

	ProtoEngine::App& ourApp = ProtoEngine::MainApp();
	ourApp.AddState<DoColor>("DoColorState");

	ourApp.Run(config);

	return 0;
}
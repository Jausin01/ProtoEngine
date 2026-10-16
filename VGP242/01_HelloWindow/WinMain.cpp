#include <ProtoEngine/Inc/ProtoEngine.h>

using namespace ProtoEngine;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	AppConfig config;
	config.appName = L"Hellow Window";

	App myApp;
	myApp.Run(config);
	return 0;
}
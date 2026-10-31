#include "Precompiled.h"
#include "ProtoEngine.h"

ProtoEngine::App& ProtoEngine::MainApp()
{
	static App sApp;
	return sApp;
}
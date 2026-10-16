#include "Precompiled.h"
#include "WindowMessageHandler.h"
#include "DebugUtil.h"

using namespace ProtoEngine;
using namespace ProtoEngine::Core;

void WindowMessageHandler::Hook(HWND window, Callback cb)
{
	mWindow = window;
	mPreviousCallBack = (Callback)GetWindowLongPtrA(window, GWLP_WNDPROC);
}

void WindowMessageHandler::Unhook()
{
	SetWindowLongA(mWindow, GWLP_WNDPROC, (LONG_PTR)mPreviousCallBack);
	mWindow = nullptr;

}

LRESULT WindowMessageHandler::ForwardMessage(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
	ASSERT(mPreviousCallBack != nullptr, "WindowMessageHandler: no callback is hooked!");
	return CallWindowProcA((WNDPROC)mPreviousCallBack, window, msg, wParam, lParam);
}
#pragma once

namespace ProtoEngine::Core
{
	class WindowMessageHandler
	{
	public:
		using Callback = LRESULT(CALLBACK*)(HWND, UINT, WPARAM, LPARAM);

		void Hook(HWND window, Callback cb);
		void Unhook();

		LRESULT ForwardMessage(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
	private:
		HWND mWindow = nullptr;
		Callback mPreviousCallBack = nullptr;
	};
}
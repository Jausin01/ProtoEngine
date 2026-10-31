#include "MainState.h"

using namespace Input;

void MainState::Initialize()
{
	LOG("Main state is initialized");
}

void MainState::Update(float deltaTime)
{
	if (InputSystem::Get()->IsKeyPressed(KeyCode::SPACE))
	{
		ProtoEngine::MainApp().ChangeState("GameState");
	}
}

void MainState::Terminate()
{
	LOG("Main state is terminated");
}
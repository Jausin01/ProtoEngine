#include "GameState.h"

using namespace ProtoEngine::Input;

void GameState::Initialize()
{
	LOG("Game state is initialized");
}

void GameState::Update(float deltaTime)
{
	if (InputSystem::Get()->IsKeyPressed(KeyCode::SPACE))
	{
		ProtoEngine::MainApp().ChangeState("MainState");
	}
}

void GameState::Terminate()
{
	LOG("Game state is terminated");
}
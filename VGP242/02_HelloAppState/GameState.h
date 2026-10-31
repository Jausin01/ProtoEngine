#pragma once
#include <ProtoEngine/Inc/ProtoEngine.h>

class GameState : public ProtoEngine::AppState
{
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Terminate() override;

};
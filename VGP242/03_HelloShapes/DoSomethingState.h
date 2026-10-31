#pragma once
#include <ProtoEngine/Inc/ProtoEngine.h>

class DoSomethingState : public ProtoEngine::AppState
{
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Terminate() override;

private:
	struct Vertex
	{
		ProtoEngine::Math::Vector3 pos = ProtoEngine::Math::Vector3::Zero;
	};
	using Vertices = std::vector<Vertex>;
	Vertices mVertices;

	// our shape information
	ID3D11Buffer* mVertexBuffer = nullptr;
	// bind to the VS function
	ID3D11VertexShader* mVertexShader = nullptr;
	// tell vs the configuration of the vertex
	ID3D11InputLayout* mInputLayout = nullptr;
	// bind to the PS function
	ID3D11PixelShader* mPixelShader = nullptr;
};
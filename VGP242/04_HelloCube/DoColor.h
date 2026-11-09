#pragma once
#include <ProtoEngine/Inc/ProtoEngine.h>

class DoColor : public ProtoEngine::AppState
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
		ProtoEngine::Color color = ProtoEngine::Colors::White;
	};
	using Vertices = std::vector<Vertex>;
	Vertices mVertices;

	ProtoEngine::Graphics::MeshBuffer mMeshBuffer;
	ProtoEngine::Graphics::VertexShader mVertexShader;
	ProtoEngine::Graphics::PixelShader mPixelShader;
	ProtoEngine::Graphics::Camera mCamera;
	ProtoEngine::Graphics::ConstantBuffer mTransformBuffer;

};
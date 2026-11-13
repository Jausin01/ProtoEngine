#include "DoColor.h"

using namespace ProtoEngine::Graphics;
using namespace ProtoEngine::Input;
using namespace ProtoEngine::Colors;

void DoColor::Initialize()
{
	// Setup camera
	mCamera.SetPosition({ 0.0f,1.0f,-3.0f });
	mCamera.SetLookAt({ 0.0f,0.0f,0.0f });

	// create a cube
	// have 6 sides
	// each side is 2 triangles
	// each triangle is 3 vertices
	// vertices must be in clockwise order

	// front
	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::Blue });
	mVertices.push_back({ { -1.0f, 1.0f, -1.0f }, Colors::Green });
	mVertices.push_back({ { 1.0f, 1.0f, -1.0f }, Colors::Green });

	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::GreenYellow });
	mVertices.push_back({ { 1.0f, 1.0f, -1.0f }, Colors::Green });
	mVertices.push_back({ { 1.0f, -1.0f, -1.0f }, Colors::Green });

	// right
	mVertices.push_back({ { 1.0f, -1.0f, -1.0f }, Colors::Lime });
	mVertices.push_back({ { 1.0f, 1.0f, -1.0f }, Colors::Green });
	mVertices.push_back({ { 1.0f, 1.0f, 1.0f }, Colors::PaleGoldenrod });

	mVertices.push_back({ { 1.0f, -1.0f, -1.0f }, Colors::BlueViolet });
	mVertices.push_back({ { 1.0f, 1.0f, 1.0f }, Colors::BlueViolet });
	mVertices.push_back({ { 1.0f, -1.0f, 1.0f }, Colors::PaleGoldenrod });

	// Left
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Lime });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::Green });
	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::PaleGoldenrod });

	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::BlueViolet });
	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::BlueViolet });
	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::PaleGoldenrod });

	// Back
	mVertices.push_back({ {  1.0f, -1.0f,  1.0f }, Colors::Blue });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::Green });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::Green });

	mVertices.push_back({ {  1.0f, -1.0f,  1.0f }, Colors::GreenYellow });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::Green });
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Green });

	// Top
	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::Lime });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::Green });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::PaleGoldenrod });

	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::BlueViolet });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::BlueViolet });
	mVertices.push_back({ {  1.0f,  1.0f, -1.0f }, Colors::PaleGoldenrod });

	// Bottom
	mVertices.push_back({ {  1.0f, -1.0f, -1.0f }, Colors::Blue });
	mVertices.push_back({ {  1.0f, -1.0f,  1.0f }, Colors::Green });
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Green });

	mVertices.push_back({ {  1.0f, -1.0f, -1.0f }, Colors::GreenYellow });
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Green });
	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::Green });

	mMeshBuffer.Initialize(mVertices.data(), sizeof(VertexPC), mVertices.size());
	std::filesystem::path shaderPath = L"../../Assets/Shaders/DoTransform.fx";
	mVertexShader.Initialize<VertexPC>(shaderPath);
	mPixelShader.Initialize(shaderPath);

	mTransformBuffer.Initialize(sizeof(Math::Matrix4));


}

void DoColor::Update(float deltaTime)
{
	InputSystem* input = InputSystem::Get();
	const float moveSpeed = (input->IsKeyDown(KeyCode::LSHIFT)) ? 10.0f : 1.0f;
	const float turnSpeed = 0.1f;
	if (input->IsKeyDown(KeyCode::W))
	{
		mCamera.Walk(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::S))
	{
		mCamera.Walk(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::D))
	{
		mCamera.Strafe(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::A))
	{
		mCamera.Strafe(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::E))
	{
		mCamera.Rise(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::Q))
	{
		mCamera.Rise(-moveSpeed * deltaTime);
	}
	if (input->IsMouseDown(MouseButton::RBUTTON))
	{
		mCamera.Yaw(input->GetMouseMoveX() * turnSpeed * deltaTime);
		mCamera.Pitch(input->GetMouseMoveY() * turnSpeed * deltaTime);
	}
}

void DoColor::Render()
{
	mVertexShader.Bind();
	mPixelShader.Bind();
	mTransformBuffer.BindVS(0);

	Math::Matrix4 matWorld = Math::Matrix4::Identity;
	Math::Matrix4 matView = mCamera.GetViewMatrix();
	Math::Matrix4 matProj = mCamera.GetProjectionMatrix();
	Math::Matrix4 matFinal = matWorld * matView * matProj;
	Math::Matrix4 wvp = Math::Transpose(matFinal);
	mTransformBuffer.Update(&wvp);

	mMeshBuffer.Render();
}


void DoColor::Terminate()
{
	mVertices.clear();
	mPixelShader.Terminate();
	mVertexShader.Terminate();
	mMeshBuffer.Terminate();
	mTransformBuffer.Terminate();
}
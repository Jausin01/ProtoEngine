#include "DoColor.h"


using namespace ProtoEngine::Graphics;
using namespace ProtoEngine::Input;
using namespace ProtoEngine::Colors;

void DoColor::Initialize()
{
	// Setup camera
	mCamera.SetPosition({ 0.0f,1.0f,-3.0f });
	mCamera.SetLookAt({ 0.0f,0.0f,0.0f });

	//MeshPX mesh = MeshBuilder::CreatePlanePX(10, 10, 1.0f, false);
	//MeshPX mesh = MeshBuilder::CreateSpherePX(30, 30, 1.0f);
	MeshPX mesh = MeshBuilder::CreateSkySpherePX(300, 300, 1.0f);
	mMeshBuffer.Initialize(mesh);
	std::filesystem::path shaderPath = L"../../Assets/Shaders/DoTexture.fx";
	mVertexShader.Initialize<VertexPX>(shaderPath);
	mPixelShader.Initialize(shaderPath);

	mTransformBuffer.Initialize(sizeof(Math::Matrix4));

	mTextureId = TextureManager::Get()->LoadTexture(L"ExplodingCat.jpg");
	mSampler.Initialize(Sampler::Filter::Linear, Sampler::AddressMode::Wrap);


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
	mSampler.BindPS(0);

	TextureManager::Get()->BindPS(mTextureId, 0);
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
	TextureManager::Get()->ReleaseTexture(mTextureId);
	mSampler.Terminate();
	mPixelShader.Terminate();
	mVertexShader.Terminate();
	mMeshBuffer.Terminate();
	mTransformBuffer.Terminate();
}
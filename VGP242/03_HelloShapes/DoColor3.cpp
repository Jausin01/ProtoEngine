#include "DoColor3.h"

using namespace ProtoEngine::Graphics;
using namespace ProtoEngine::Input;
using namespace ProtoEngine::Colors;

void DoColor3::Initialize()
{
	// Leg 1
	mVertices.push_back({ { -0.2f, -0.7f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { -0.2f, -0.3f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { -0.08f, -0.3f, 0.3f }, Colors::Blue });

	mVertices.push_back({ { -0.2f, -0.7f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { -0.08f, -0.3f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { -0.08f, -0.7f, 0.3f }, Colors::Blue });

	// Leg 2
	mVertices.push_back({ { 0.08f, -0.7f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { 0.08f, -0.3f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { 0.2f, -0.3f, 0.3f }, Colors::Blue });

	mVertices.push_back({ { 0.08f, -0.7f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { 0.2f, -0.3f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { 0.2f, -0.7f, 0.3f }, Colors::Blue });

	// left foot 1
	mVertices.push_back({ { -0.3f, -0.78f, 0.2f }, Colors::Red });
	mVertices.push_back({ { -0.3f, -0.7f, 0.2f }, Colors::Red });
	mVertices.push_back({ { -0.08f, -0.7f, 0.2f }, Colors::Red });

	mVertices.push_back({ { -0.3f, -0.78f, 0.2f }, Colors::Red });
	mVertices.push_back({ { -0.08f, -0.7f, 0.2f }, Colors::Red });
	mVertices.push_back({ { -0.08f, -0.78f, 0.2f }, Colors::Red });

	// right foot 2
	mVertices.push_back({ { 0.08f, -0.78f, 0.2f }, Colors::Red });
	mVertices.push_back({ { 0.08f, -0.7f, 0.2f }, Colors::Red });
	mVertices.push_back({ { 0.3f, -0.7f, 0.2f }, Colors::Red });

	mVertices.push_back({ { 0.08f, -0.78f, 0.2f }, Colors::Red });
	mVertices.push_back({ { 0.3f, -0.7f, 0.2f }, Colors::Red });
	mVertices.push_back({ { 0.3f, -0.78f, 0.2f }, Colors::Red });

	// body
	mVertices.push_back({ { -0.3f, -0.3f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { -0.3f, 0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { 0.3f, 0.2f, 0.3f }, Colors::Green });

	mVertices.push_back({ { -0.3f, -0.3f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { 0.3f, 0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { 0.3f, -0.3f, 0.3f }, Colors::Blue });

	// chest button
	mVertices.push_back({ { -0.08f, -0.15f, 0.1f }, Colors::Red });
	mVertices.push_back({ { -0.08f, 0.0f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.08f, 0.0f, 0.1f }, Colors::Red });

	mVertices.push_back({ { -0.08f, -0.15f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.08f, 0.0f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.08f, -0.15f, 0.1f }, Colors::Red });

	// arm 1
	mVertices.push_back({ { -0.45f, -0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { -0.45f, 0.15f, 0.3f }, Colors::Green });
	mVertices.push_back({ { -0.3f, 0.15f, 0.3f }, Colors::Green });

	mVertices.push_back({ { -0.45f, -0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { -0.3f, 0.15f, 0.3f }, Colors::Green });
	mVertices.push_back({ { -0.3f, -0.2f, 0.3f }, Colors::Green });

	// arm 2
	mVertices.push_back({ { 0.3f, -0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { 0.3f, 0.15f, 0.3f }, Colors::Green });
	mVertices.push_back({ { 0.45f, 0.15f, 0.3f }, Colors::Green });

	mVertices.push_back({ { 0.3f, -0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { 0.45f, 0.15f, 0.3f }, Colors::Green });
	mVertices.push_back({ { 0.45f, -0.2f, 0.3f }, Colors::Green });

	// head 
	mVertices.push_back({ { -0.25f, 0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { -0.25f, 0.65f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { 0.25f, 0.65f, 0.3f }, Colors::Blue });

	mVertices.push_back({ { -0.25f, 0.2f, 0.3f }, Colors::Green });
	mVertices.push_back({ { 0.25f, 0.65f, 0.3f }, Colors::Blue });
	mVertices.push_back({ { 0.25f, 0.2f, 0.3f }, Colors::Green });

	// Eye 1
	mVertices.push_back({ { -0.17f, 0.4f, 0.1f }, Colors::Red });
	mVertices.push_back({ { -0.17f, 0.52f, 0.1f }, Colors::Red });
	mVertices.push_back({ { -0.07f, 0.52f, 0.1f }, Colors::Red });

	mVertices.push_back({ { -0.17f, 0.4f, 0.1f }, Colors::Red });
	mVertices.push_back({ { -0.07f, 0.52f, 0.1f }, Colors::Red });
	mVertices.push_back({ { -0.07f, 0.4f, 0.1f }, Colors::Red });

	// Eye 2
	mVertices.push_back({ { 0.07f, 0.4f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.07f, 0.52f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.17f, 0.52f, 0.1f }, Colors::Red });

	mVertices.push_back({ { 0.07f, 0.4f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.17f, 0.52f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.17f, 0.4f, 0.1f }, Colors::Red });

	// mouth
	mVertices.push_back({ { -0.12f, 0.27f, 0.1f }, Colors::Red });
	mVertices.push_back({ { -0.12f, 0.33f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.12f, 0.33f, 0.1f }, Colors::Red });

	mVertices.push_back({ { -0.12f, 0.27f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.12f, 0.33f, 0.1f }, Colors::Red });
	mVertices.push_back({ { 0.12f, 0.27f, 0.1f }, Colors::Red });


	// start creating the components that communicate with GPU
	auto device = GraphicsSystem::Get()->GetDevice();

	// build the vertex buffer, which stores the vertices to the GPU
	D3D11_BUFFER_DESC bufferDecs{};
	bufferDecs.ByteWidth = static_cast<UINT>(mVertices.size()) * sizeof(Vertex);
	bufferDecs.Usage = D3D11_USAGE_DEFAULT;
	bufferDecs.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDecs.MiscFlags = 0;
	bufferDecs.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = mVertices.data();

	HRESULT hr = device->CreateBuffer(&bufferDecs, &initData, &mVertexBuffer);
	ASSERT(SUCCEEDED(hr), "Failed to create vertex buffer");

	std::filesystem::path shaderFilePath = L"../../Assets/Shaders/DoColor.fx";

	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	ID3DBlob* shaderBlob = nullptr;
	ID3DBlob* errorBlob = nullptr;
	hr = D3DCompileFromFile(
		shaderFilePath.c_str(),
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE,
		"VS", "vs_5_0",
		shaderFlags, 0,
		&shaderBlob,
		&errorBlob);
	if (errorBlob != nullptr && errorBlob->GetBufferPointer() != nullptr)
	{
		LOG("%s", static_cast<const char*>(errorBlob->GetBufferPointer()));
	}
	ASSERT(SUCCEEDED(hr), "Failed to compile vertex shader");

	hr = device->CreateVertexShader(
		shaderBlob->GetBufferPointer(),
		shaderBlob->GetBufferSize(),
		nullptr,
		&mVertexShader);

	ASSERT(SUCCEEDED(hr), "Failed to compile vertex shader");
	// =======================
	// what is the make up 
	std::vector<D3D11_INPUT_ELEMENT_DESC> vertexLayout;
	vertexLayout.push_back({ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT });
	vertexLayout.push_back({ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT });

	hr = device->CreateInputLayout(
		vertexLayout.data(),
		static_cast<UINT>(vertexLayout.size()),
		shaderBlob->GetBufferPointer(),
		shaderBlob->GetBufferSize(),
		&mInputLayout);
	ASSERT(SUCCEEDED(hr), "Failed to create input layout");
	SafeRelease(shaderBlob);
	SafeRelease(errorBlob);
	//====================================================================================
	// bind pixel shader to shader file
	hr = D3DCompileFromFile(shaderFilePath.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "PS", "ps_5_0", shaderFlags, 0, &shaderBlob, &errorBlob);
	if (errorBlob != nullptr && errorBlob->GetBufferPointer() != nullptr)
	{
		LOG("%s", static_cast<const char*>(errorBlob->GetBufferPointer()));
	}

	hr = device->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, &mPixelShader);
	ASSERT(SUCCEEDED(hr), "Failed to create pixel shader");
	SafeRelease(shaderBlob);
	SafeRelease(errorBlob);
}

void DoColor3::Update(float deltaTime)
{
	if (InputSystem::Get()->IsKeyPressed(KeyCode::SPACE))
	{
		MainApp().ChangeState("DoSomethingState");
	}
}

void DoColor3::Render()
{
	auto context = GraphicsSystem::Get()->GetContext();

	// bind all the buffers
	context->VSSetShader(mVertexShader, nullptr, 0);
	context->IASetInputLayout(mInputLayout);
	context->PSSetShader(mPixelShader, nullptr, 0);

	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// draw
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	context->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);
	context->Draw(static_cast<UINT>(mVertices.size()), 0);
}


void DoColor3::Terminate()
{
	mVertices.clear();
	SafeRelease(mPixelShader);
	SafeRelease(mInputLayout);
	SafeRelease(mVertexShader);
	SafeRelease(mVertexBuffer);
}
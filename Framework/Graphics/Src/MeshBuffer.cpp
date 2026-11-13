#include "Precompiled.h"
#include "MeshBuffer.h"
#include "GraphicsSystem.h"

using namespace ProtoEngine;
using namespace ProtoEngine::Graphics;


void MeshBuffer::Initialize(const void* vertices, uint32_t vertexSize, uint32_t vertexCount)
{
	CreateVertexBuffer(vertices, vertexSize, vertexCount);
}

void ProtoEngine::Graphics::MeshBuffer::Initialize(const void* vertices, uint32_t vertexSize, uint32_t vertexCount, const void* indices, uint32_t indexCount)
{
	CreateVertexBuffer(vertices, vertexSize, vertexCount);
	CreateIndexBuffer(indices, indexCount);
}

void MeshBuffer::SetTopology(Topology topology)
{
	switch (topology)
	{
	case Topology::Points: mTopology = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST; break;
	case Topology::Lines: mTopology = D3D11_PRIMITIVE_TOPOLOGY_LINELIST; break;
	case Topology::Triangles: mTopology = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST; break;
	default:
		break;
	}
}

void MeshBuffer::Terminate()
{
	SafeRelease(mVertexBuffer);
}

void MeshBuffer::Render() const
{
	auto context = GraphicsSystem::Get()->GetContext();
	context->IASetPrimitiveTopology(mTopology);

	UINT offset = 0;
	context->IASetVertexBuffers(0, 1, &mVertexBuffer, &mVertexSize, &offset);
	if (mIndexBuffer != nullptr)
	{
		context->IASetIndexBuffer(mIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		context->DrawIndexed((UINT)mIndexCount, 0, 0);
	}
	else
	{
		context->Draw(mVertexCount, 0);
	}
	
}


void MeshBuffer::CreateVertexBuffer(const void* vertices, uint32_t vertexSize, uint32_t vertexCount)
{
	// start creating the components that communicate with GPU
	mVertexSize = vertexSize;
	mVertexCount = vertexCount;
	auto device = GraphicsSystem::Get()->GetDevice();

	// build the vertex buffer, which stores the vertices to the GPU
	D3D11_BUFFER_DESC bufferDecs{};
	bufferDecs.ByteWidth = vertexSize * vertexCount;
	bufferDecs.Usage = D3D11_USAGE_DEFAULT;
	bufferDecs.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDecs.MiscFlags = 0;
	bufferDecs.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = vertices;

	HRESULT hr = device->CreateBuffer(&bufferDecs, &initData, &mVertexBuffer);
	ASSERT(SUCCEEDED(hr), "Failed to create vertex buffer");

}

void ProtoEngine::Graphics::MeshBuffer::CreateIndexBuffer(const void* indices, uint32_t IndexCount)
{
	if (IndexCount == 0)
	{
		return;
	}

	mIndexCount = IndexCount;

	auto device = GraphicsSystem::Get()->GetDevice();

	D3D11_BUFFER_DESC bufferDecs{};
	bufferDecs.ByteWidth = static_cast<UINT>(IndexCount) * sizeof(uint32_t);
	bufferDecs.Usage = D3D11_USAGE_DEFAULT;
	bufferDecs.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bufferDecs.MiscFlags = 0;
	bufferDecs.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA initData{};
	initData.pSysMem = indices;

	HRESULT hr = device->CreateBuffer(&bufferDecs, &initData, &mIndexBuffer);
	ASSERT(SUCCEEDED(hr), "Failed to create index buffer");
}

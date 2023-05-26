#pragma once
#include "Object.h"

class Material;

struct IndexBufferInfo
{
	ComPtr<ID3D12Resource>		buffer;
	D3D12_INDEX_BUFFER_VIEW		bufferView;
	DXGI_FORMAT					format;
	uint32						count;
};

class Mesh : public Object
{
public:
	Mesh();
	virtual ~Mesh();

	void Create(const vector<Vertex>& vertexBuffer, const vector<uint32>& indexbuffer);
	void Render(uint32 instanceCount = 1, uint32 idx = 0);
	void Render(shared_ptr<class InstancingBuffer>& buffer, uint32 idx = 0);

	static shared_ptr<Mesh> CreateFromFBX(const struct FbxMeshInfo* meshInfo);

private:
	void CreateVertexBuffer(const vector<Vertex>& buffer);
	void CreateIndexBuffer(const vector<uint32>& buffer);

public:
	uint32 GetSubsetCount() { return static_cast<uint32>(_vecIndexInfo.size()); }

private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {};
	uint32 _vertexCount = 0;

	vector<IndexBufferInfo>		_vecIndexInfo;
};


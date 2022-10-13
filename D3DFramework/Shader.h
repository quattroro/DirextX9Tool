#pragma once
#include "Object.h"


class Shader :public Object
{
public:
	Shader();
	virtual ~Shader();

	void Init(const wstring& path);
	void Update();

private:
	void CreateShader();
	void CreateVertexShader(const wstring& path, const string& name, const string& version);
	void CreatePixelShader(const wstring& path, const string& name, const string& version);

	//void CreateShader(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob, D3D12_SHADER_BYTECODE& shaderByteCode);
	//void CreateVertexShader(const wstring& path, const string& name, const string& version);
	//void CreatePixelShader(const wstring& path, const string& name, const string& version);
private:
	LPDIRECT3DVERTEXSHADER9 _verShader;
	LPDIRECT3DPIXELSHADER9 _pixShader;
};


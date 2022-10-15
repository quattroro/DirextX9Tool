#include "pch.h"
#include "Shader.h"

extern LPDIRECT3DDEVICE9   g_pd3dDevice;

Shader::Shader():Object(OBJECT_TYPE::SHADER)
{
	



}

Shader::~Shader()
{
}

void Shader::Init(const wstring& path)
{
	//D3DVERTEXELEMENT9	decl[3];
	// FVF를 사용해서 정점선언값을 자동으로 채워넣는다
	//D3DXDeclaratorFromFVF(D3DFVF_CUSTOMVERTEX, decl);
	// 정점선언값으로 g_pDecl을 생성한다.
	//g_pd3dDevice->CreateVertexDeclaration(decl, &g_pDecl);

	CreateVertexShader(path, "VS_Main", "vs_2_0");
	CreatePixelShader(path, "PS_Main", "ps_2_0");
}

void Shader::Update()
{
}

void Shader::CreateShader()
{
	LPD3DXBUFFER buff = NULL;
	LPD3DXBUFFER err = NULL;
	DWORD dwFlags = 0;
	LPD3DXCONSTANTTABLE pTbv;
	//해당 함수로 셰이더를 읽어오고
	D3DXCompileShaderFromFile(
		L"../Resources/shader/Test.hlsli"
		, NULL
		, NULL
		,/*진입점 함수*/"VS_Main"
		,/*버전*/"vs_5_0"
		, dwFlags//컴파일 플래그
		, &buff//컴파일된 셰이더 코드를 가지는 ID3DXBUFFER포인터
		, &err//에러메시지 가지는 ID3DXBUFFER포인터
		, &pTbv//셰이더의 상수 테이블 데이터
	);
	//D3DXCompileShaderFromFile
	//d3dxCompile
	LPDIRECT3DVERTEXSHADER9 p_shader;
	g_pd3dDevice->CreateVertexShader((DWORD*)buff->GetBufferPointer(), &p_shader);
	
	
}

void Shader::CreateVertexShader(const wstring& path, const string& name, const string& version)
{
	LPD3DXBUFFER buff = NULL;
	LPD3DXBUFFER err = NULL;
	DWORD dwFlags = 0;
	LPD3DXCONSTANTTABLE pTbv;
	//해당 함수로 셰이더를 읽어오고
	D3DXCompileShaderFromFile(
		path.c_str()
		, NULL
		, NULL
		, name.c_str()/*진입점 함수*/
		, version.c_str()/*버전*/
		, dwFlags//컴파일 플래그
		, &buff//컴파일된 셰이더 코드를 가지는 ID3DXBUFFER포인터
		, &err//에러메시지 가지는 ID3DXBUFFER포인터
		, &pTbv//셰이더의 상수 테이블 데이터
	);




	//g_pd3dDevice->CreateVertexDeclaration

	g_pd3dDevice->CreateVertexShader((DWORD*)buff->GetBufferPointer(), &_verShader);
}

void Shader::CreatePixelShader(const wstring& path, const string& name, const string& version)
{
	LPD3DXBUFFER buff = NULL;
	LPD3DXBUFFER err = NULL;
	DWORD dwFlags = 0;
	LPD3DXCONSTANTTABLE pTbv;
	//해당 함수로 셰이더를 읽어오고
	D3DXCompileShaderFromFile(
		path.c_str()
		, NULL
		, NULL
		, name.c_str()/*진입점 함수*/
		, version.c_str()/*버전*/
		, dwFlags//컴파일 플래그
		, &buff//컴파일된 셰이더 코드를 가지는 ID3DXBUFFER포인터
		, &err//에러메시지 가지는 ID3DXBUFFER포인터
		, &pTbv//셰이더의 상수 테이블 데이터
	);
	
	g_pd3dDevice->CreatePixelShader((DWORD*)buff->GetBufferPointer(), &_pixShader);
	//g_pd3dDevice->SetPixelShader(_pixShader);

}

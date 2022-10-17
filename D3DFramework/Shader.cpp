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
	// FVF�� ����ؼ� ���������� �ڵ����� ä���ִ´�
	//D3DXDeclaratorFromFVF(D3DFVF_CUSTOMVERTEX, decl);
	// ������������ g_pDecl�� �����Ѵ�.
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
	//�ش� �Լ��� ���̴��� �о����
	D3DXCompileShaderFromFile(
		L"../Resources/shader/Test.hlsli"
		, NULL
		, NULL
		,/*������ �Լ�*/"VS_Main"
		,/*����*/"vs_5_0"
		, dwFlags//������ �÷���
		, &buff//�����ϵ� ���̴� �ڵ带 ������ ID3DXBUFFER������
		, &err//�����޽��� ������ ID3DXBUFFER������
		, &pTbv//���̴��� ��� ���̺� ������
	);
	//D3DXCompileShaderFromFile
	//d3dxCompile
	LPDIRECT3DVERTEXSHADER9 p_shader;
	g_pd3dDevice->CreateVertexShader((DWORD*)buff->GetBufferPointer(), &p_shader);
	
	//D3DVERTEXELEMENT9 vertecelement=
	//{
	//	/*���ؽ� ��Ұ� ����� ��Ʈ���� �����Ѵ�.*/,
	//	/*���ؽ� ����ü ���� ���ؽ� ��ҷ��� ������ ����Ű�� ����Ʈ ������ ������, ���� ��� 
	//	������ ���� ���ؽ� ����ü�� �ִٸ� (vector3 pos, vector3 normal) pos�� 0 normal�� 12 �� �ȴ�.*/,
	//	/*������ ���� �����Ѵ�. D3DDECLTYPE �������� ��� �� � ���̳� �� �� �ִ�.*/
	//	/*�ε� �Ҽ��� ��Į��*/
	//	/*2D �ε� �Ҽ��� ����*/
	//	/*3D �ε� �Ҽ��� ����*/
	//	/*4D �ε� �Ҽ��� ����*/
	//	/*Į��*/,
	//	/*����ȭ(�׼����̼�) ����� �����Ѵ�.*/,
	//	/*���ؽ� ����� ��ȹ�� �뵵�� �����Ѵ�. (��ġ����, ��������ǥ ���)*/,
	//	/*���ؽ� ����Ʈ�� ũ�⸦ ����, */,
	//	/*������ �뵵 ������ �ټ��� ���ؽ� ��Ҹ� �ĺ��ϴµ� �̿�*/
	//}


}

void Shader::CreateVertexShader(const wstring& path, const string& name, const string& version)
{
	//GetDeviceCaps()
	LPD3DXBUFFER buff = NULL;
	LPD3DXBUFFER err = NULL;
	DWORD dwFlags = 0;

	


	LPD3DXCONSTANTTABLE pTbv;//�ش� ���̴��� ������Ʈ ���̺��� �޾ƿ´�.
	//LPD3DXCONSTANTTABLE pTbv
	//�ش� �Լ��� ���̴��� �о����
	HRESULT r = D3DXCompileShaderFromFile(
		L"Test.txt"
		, NULL
		, NULL
		, "VS_Main"/*������ �Լ�*/
		, "vs_2_0"/*����*/
		, dwFlags//������ �÷���
		, &buff//�����ϵ� ���̴� �ڵ带 ������ ID3DXBUFFER������
		, &err//�����޽��� ������ ID3DXBUFFER������
		, &pTbv//���̴��� ��� ���̺� ������
	);

	if(err)
	{
		::MessageBox(0, (WCHAR*)err->GetBufferPointer(), 0, 0);
		//Release<>
	}

	if (r == D3DERR_INVALIDCALL)
	{
		int a = 0;
	}
	else if (r == D3DXERR_INVALIDDATA)
	{
		int a = 0;
	}
	else if (r == E_OUTOFMEMORY)
	{
		int a = 0;
	}

	/*���ϴ� ������ �����ϴ� �θ� ����ü�� �ĺ��ϱ� ���� D3DXHANDLE, ���� ��� Ư�� ����ü �ν��Ͻ����� ������ ��� �ڵ���
	���Ѵٸ� ����� ����ü �ν��Ͻ����� �ڵ��� �����Ѵ�. 
	���� �ֻ��� �������� �ڵ��� ����� �Ѵٸ� �� ���ڿ� 0�� �����Ѵ�.*/
	//D3DXHANDLE h0 = ConstTable->GetComstantByName(0/*����� ��ȿ ���� ���ϴ� ������ �����ϴ�  */,"������")
	//ID3DXConstantTable::setXXX("��� ���̺�� ����� ��ġ�� ������", "�����Ϸ��� ������ �����ϴ� �ڵ�", "��");
	//�迭�� ������ ������ �������� �迭�� ũ�� �Ӽ��� �߰��ȴ�.

	//g_pd3dDevice->CreateVertexDeclaration

	g_pd3dDevice->CreateVertexShader((DWORD*)buff->GetBufferPointer(), &_verShader);
}

void Shader::CreatePixelShader(const wstring& path, const string& name, const string& version)
{
	LPD3DXBUFFER buff = NULL;
	LPD3DXBUFFER err = NULL;
	DWORD dwFlags = 0;
	LPD3DXCONSTANTTABLE pTbv;
	//�ش� �Լ��� ���̴��� �о����
	D3DXCompileShaderFromFile(
		path.c_str()
		, NULL
		, NULL
		, name.c_str()/*������ �Լ�*/
		, version.c_str()/*����*/
		, dwFlags//������ �÷���
		, &buff//�����ϵ� ���̴� �ڵ带 ������ ID3DXBUFFER������
		, &err//�����޽��� ������ ID3DXBUFFER������
		, &pTbv//���̴��� ��� ���̺� ������
	);
	
	g_pd3dDevice->CreatePixelShader((DWORD*)buff->GetBufferPointer(), &_pixShader);
	//g_pd3dDevice->SetPixelShader(_pixShader);

}

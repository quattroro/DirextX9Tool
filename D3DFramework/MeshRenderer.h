#pragma once
#include "Component.h"

class Mesh;
class Material;

//�ش� ���� ������Ʈ�� mesh�� material �� �����Ѵ�.
class MeshRenderer:public Component
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	void setMesh(Mesh* mesh) { _mesh = mesh; }
	void setMaterial(Material* mat) { _material = mat; }

	//������ ����Ѵ�.
	void Render();

private:
	Mesh* _mesh = nullptr;
	Material* _material = nullptr;

};


#pragma once
#include "pch.h"

class Transform
{
public:
	Transform();
	virtual ~Transform();

public:
	//SetLocalPosition()


private:
	Vector3 _localPotision;
	Vector3 _localRotation;
	Vector3 _localScale = { 1.f,1.f,1.f };

	Matrix _matLocal = {};
	Matrix _matWorld = {};

	Transform* _parent;
};


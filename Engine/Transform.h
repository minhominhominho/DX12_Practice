#pragma once
#include "Component.h"

struct TransformMatrix
{
	Vec4 offset;
};


class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	// TODO : �°� Parent/Child ����

private:
	// TODO : World ��ġ ����

};


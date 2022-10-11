#include "pch.h"
#include "Component.h"


Component::Component(COMPONENT_TYPE type) :Object(OBJECT_TYPE::COMPONENT), _type(type)
{

}

Component::~Component()
{
}

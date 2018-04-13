#include "stdafx.h"
#include "G_Object.h"

static _int64  Object_Count = 0;

G_Object::G_Object()
{
	++Object_Count;
	m_objectIndex = Object_Count;
}


G_Object::~G_Object()
{
}
void G_Object::ShowObjectIndex()
{
	printf("m_object index = %d, Count = %d\n",m_objectIndex, Object_Count);
}
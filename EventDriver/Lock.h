#pragma once
#include "ObjectLockable.h"
class Lock
{
public:
	Lock(ObjectLockable &obj):m_Obj(obj)
	{
		EnterCriticalSection(&m_Obj.m_Section);
	}
	~Lock(void)
	{
		LeaveCriticalSection(&m_Obj.m_Section);
	}
private: 
	ObjectLockable &m_Obj;
};


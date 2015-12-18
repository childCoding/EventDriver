#pragma once
#include <windows.h>
//template<Obj>
class ObjectLockable
{
	friend class Lock;
public:
	ObjectLockable(void)
	{
		InitializeCriticalSection(&m_Section);
	}
	~ObjectLockable(void)
	{
		DeleteCriticalSection(&m_Section);
	}
private:
	CRITICAL_SECTION m_Section;
};


#pragma once
#include "ObjectLockable.h"
#include "Lock.h"
#include <queue>
template<typename T>
class SafeQueue :public ObjectLockable
{
public:
	SafeQueue(void);
	~SafeQueue(void);

	void push(T& item);
	T& pop();
	void clear();
	size_t size();
private:
	std::queue<T> m_queue;
};


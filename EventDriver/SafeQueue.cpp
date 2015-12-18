#include "SafeQueue.h"
template<typename T>
SafeQueue<T>::SafeQueue(void)
{
}

template<typename T>
SafeQueue<T>::~SafeQueue(void)
{
	
}

template<typename T>
void SafeQueue<T>::push(T& item)
{
	Lock locker(*this);
	m_queue.push(item);
}
template<typename T>
T& SafeQueue<T>::pop()
{
	Lock locker(*this);
	return m_queue.pop();
}

template<typename T>
void SafeQueue<T>::clear()
{
	Lock locker(*this);
	while(!m_queue.empty()) m_queue.pop();
}

template<typename T>
size_t SafeQueue<T>::size()
{
	return m_queue.size();
}
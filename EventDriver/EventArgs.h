#pragma once
class EventArgs
{
public:
	EventArgs(){}
	virtual	~EventArgs(){}
};

class GameEventArgs :public EventArgs
{
	GameEventArgs(){}
	virtual ~GameEventArgs(){}
	void *pData;
};
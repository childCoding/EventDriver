#pragma once
#include "Event.h"
#include "EventArgs.h"
#include <functional>

class FunctionSlot
{
public:
	typedef std::function < bool(EventArgs&)> Function;

	FunctionSlot(Function fun):d_functor(fun){}
	~FunctionSlot(){}
	bool operator()(EventArgs& args){ return d_functor(args); }
private:
	Function d_functor;
};


#pragma once
#include "FunctionSlot.h"
#include "Event.h"
#include <map>

class EventSet
{
public:

#define MakeFunction(fun,optr) FunctionSlot::Function(std::bind(fun,optr,std::placeholders::_1))
#define RegEvent(id,obj,fun) BindEvent(id,MakeFunction(&C::onMouseDown, obj))

	EventSet(){}
	~EventSet(){}

	void AddEvent(size_t event_id);

	bool BindEvent(size_t event_id, FunctionSlot fun);
	void fireEvent(size_t event_id, EventArgs& args);
	Event* getTypeObject(size_t event_id,bool autoAdd = true);


private:
	typedef std::map<size_t, Event*> EventMap;
	EventMap d_events;


};

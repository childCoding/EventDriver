#pragma once
#include "EventArgs.h"
#include "FunctionSlot.h"
#include <map>

class FunctionSlot;

class Event
{
	typedef size_t Order;
	typedef std::multimap<Order, FunctionSlot> SlotContainer;
	SlotContainer d_slots;
	static const Order DefaultOrder = 0;			//Ä¬ÈÏµÄË³Ðò
public:
	Event(size_t id) :d_id(id){}
	void subscribe(FunctionSlot fun);
	void operator()(EventArgs& args);
	size_t getid(){ return d_id; }
private:
	size_t d_id;
};


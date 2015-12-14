#include "EventSet.h"

void EventSet::AddEvent(size_t event_id)
{

	d_events.insert(EventMap::value_type(event_id, new Event(event_id)));
}
bool EventSet::BindEvent(size_t event_id, FunctionSlot fun)
{
	EventMap::iterator it = d_events.find(event_id);
	it->second->subscribe(fun);
	return true;
}

void EventSet::fireEvent(size_t event_id, EventArgs& args)
{
	Event* ev = getTypeObject(event_id);
	if (ev != 0)
		(*ev)(args);
}

Event* EventSet::getTypeObject(size_t event_id,bool autoAdd)
{
	EventMap::iterator evs = d_events.find(event_id);

	if (evs == d_events.end())
	{
		if (autoAdd)
		{
			AddEvent(event_id);
			return d_events.find(event_id)->second;
		}
		return NULL;
	}
	return evs->second;
}
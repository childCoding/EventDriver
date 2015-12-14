#include "Event.h"
void Event::subscribe(FunctionSlot fun)
{
	d_slots.insert(std::pair<Order, FunctionSlot>(DefaultOrder, fun));

}

void Event::operator()(EventArgs& args)
{
	for (auto ev : d_slots)
	{
		ev.second(args);
	}
}

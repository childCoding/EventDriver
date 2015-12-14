// ccccccccccccccc.cpp : 定义控制台应用程序的入口点。
//

#include "FunctionSlot.h"
#include "EventSet.h"

class C :public EventSet
{

public:
	//std::function< bool(EventArgs&)> fun;
	C(){
		AddEvent(1);
		//BindEvent(1, MakeFunction(&C::onMouseDown, this));
		RegEvent(1, this, C::onMouseDown);
		//fun = &C::onMouseDown;
	}
	void operator()(int i){  }
	void fire(size_t id)
	{
		EventArgs args;
		fireEvent(id, args);
	}
	bool onMouseDown(EventArgs &args)
	{
		printf("aaaaaaaaaaaaa");
		return true;
	}
};

int main(int argc, char* argv[])
{
	C c;
	c.fire(1);
	//printf("%d size:",1);
	return 0;
}


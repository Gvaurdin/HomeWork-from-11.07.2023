#include "Check.h"
#include "Buy.h"

ostream& operator<<(ostream& os, Check& c)
{
	c.Print_order();
	return os;
}


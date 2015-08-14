#include "LibA.h"
#include "LibB.h"
#include "CommonC1.hpp"


void CallPrintTestA()
{
	CommonC::PrintTest();
	CallPrintTestB();
}

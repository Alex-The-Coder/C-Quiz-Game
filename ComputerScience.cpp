#include "ComputerScience.h"
#include "VariableStage.h"
#include "LoopStage.h"
#include "PointerStage.h"
using namespace std;

ComputerScience::ComputerScience() : Game("Computer Science: FINAL EXAM", 3)
{
	setup();
}

void ComputerScience::setup()
{
	this->addStage(new VariableStage());
	this->addStage(new LoopStage());
	this->addStage(new PointerStage());
}

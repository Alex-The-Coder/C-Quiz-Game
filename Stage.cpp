#include "Stage.h"

Stage::Stage(string name)
{
	this->name = name;
}

const string& Stage::getName()
{
	return name;
}

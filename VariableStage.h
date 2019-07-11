#ifndef VARIABLESTAGE_H_
#define VARIABLESTAGE_H_

#include "Stage.h"

class VariableStage : public Stage
{
private:
	int score;
	string statements[5];
	string answers[5];
	bool caseMatters[5] = { true };
protected:
	virtual void prepare();
public:
	VariableStage();

	virtual int start();
};

#endif /* VARIABLESTAGE_H_ */

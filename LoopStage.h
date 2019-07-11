#ifndef LOOPSTAGE_H_
#define LOOPSTAGE_H_

#include "Stage.h"

class LoopStage : public Stage
{
private:
	int score;
	string statements[5];
	string answers[5];
protected:
	virtual void prepare();
public:
	LoopStage();

	virtual int start();
};

#endif /* LOOPSTAGE_H_ */

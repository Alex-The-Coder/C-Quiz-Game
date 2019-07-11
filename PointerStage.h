#ifndef POINTERSTAGE_H_
#define POINTERSTAGE_H_

#include "Stage.h"

class PointerStage : public Stage
{
private:
	int score;
	string statements[5];
	string answers[5];
protected:
	virtual void prepare();
public:
	PointerStage();

	virtual int start();
};

#endif /* POINTERSTAGE_H_ */

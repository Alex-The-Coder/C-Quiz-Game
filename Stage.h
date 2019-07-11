#ifndef STAGE_H_
#define STAGE_H_

#include <string>
using namespace std;

class Stage
{
private:
	string name;
protected:
	virtual void prepare() = 0;
public:
	Stage(string name);

	const string& getName();

	virtual int start() = 0;
};

#endif /* STAGE_H_ */

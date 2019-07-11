#ifndef GAME_H_
#define GAME_H_

#include <string>
#include "Stage.h"
using namespace std;

class Game
{
private:
	int score;
	string name;
	int currentStage;
	int stageCount;
	int totalStages;
	Stage** stages;
protected:
	bool initialized();
	void addStage(Stage* stage);
	virtual void setup() = 0;
public:
	Game(string name, int totalStages);

	string getName();
	void begin();

	static void delay(unsigned long milliseconds);
	static void trimString(string& str);
	static void lowercase(string& str);
};

#endif /* GAME_H_ */

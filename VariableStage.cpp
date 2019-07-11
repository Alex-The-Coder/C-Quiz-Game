#include "VariableStage.h"
#include "Game.h"
#include <string>
#include <iostream>
using namespace std;

VariableStage::VariableStage() : Stage("Variables")
{
	prepare();
}

void VariableStage::prepare()
{
	statements[0] = "int x = 5;";
	answers[0] = "5";

	statements[1] = "double y = 10.0;";
	answers[1] = "10.0";

	statements[2] = "char c = 'a';";
	answers[2] = "a";

	statements[3] = "bool b = true;";
	answers[3] = "true";
	caseMatters[3] = false;

	statements[4] = "int x = (5 + 15);";
	answers[4] = "20";
}

int VariableStage::start()
{
	cout << "For each assignment statement, determine what the final value of each variable will be." << endl;
	Game::delay(500L);

	for (int i = 0; i < 5; i++)
	{
		cout << "Statement " << (i + 1) << ":" << endl;
		cout << statements[i] << endl;
		cout << "Your Answer: ";
		string answer;
		getline(cin, answer);
		Game::trimString(answer);

		if (!caseMatters[i])
		{
			Game::lowercase(answer);
		}

		if (answer == answers[i])
		{
			int score = 100 + (i * 100);
			cout << "CORRECT! +" << score << " points" << endl;
			this->score += score;
		}
		else
		{
			cout << "INCORRECT" << endl;
		}

		Game::delay(200L);
	}

	Game::delay(100L);
	cout << "FINAL SCORE: " << score << endl;

	return score;
}

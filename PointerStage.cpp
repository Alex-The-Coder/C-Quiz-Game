#include "PointerStage.h"
#include "Game.h"
#include <string>
#include <iostream>
using namespace std;

PointerStage::PointerStage() : Stage("Pointers")
{
	prepare();
}

void PointerStage::prepare()
{
	statements[0] = "Where is the new object allocated in line 1?";
	answers[0] = "heap";

	statements[1] = "What should replace _ in line 2?";
	answers[1] = "->";

	statements[2] = "What line of code should precede line 3?";
	answers[2] = "delete o;";

	statements[3] = "Does Object o have any memory allocated to it after line 3? (Yes/No)";
	answers[3] = "no";

	statements[4] = "What happens if the memory allocated to Object o is not explicitly released?";
	answers[4] = "memory leak";
}

int PointerStage::start()
{
	cout << "For the following code, answer each question." << endl;
	Game::delay(100L);
	cout << "Object* o = new Object();" << endl;
	cout << "o_someMethod();" << endl;
	cout << "o = nullptr;" << endl;
	Game::delay(500L);

	for (int i = 0; i < 5; i++)
	{
		cout << "Question " << (i + 1) << ":" << endl;
		cout << statements[i] << endl;
		cout << "Your Answer: ";
		string answer;
		getline(cin, answer);
		Game::trimString(answer);
		Game::lowercase(answer);

		if (answer == answers[i])
		{
			int score = 300 + (i * 300);
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

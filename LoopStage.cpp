#include "LoopStage.h"
#include "Game.h"
#include <string>
#include <iostream>
using namespace std;

LoopStage::LoopStage() : Stage("Loops")
{
	prepare();
}

void LoopStage::prepare()
{
	statements[0] = "What will i be during the last iteration of the loop?";
	answers[0] = "9";

	statements[1] = "What will x be after one iteration of the loop?";
	answers[1] = "10";

	statements[2] = "What will y be after two iterations of the loop?";
	answers[2] = "21";

	statements[3] = "How many times will the code inside the loop be run?";
	answers[3] = "10";

	statements[4] = "What is the value of z?";
	answers[4] = "36288125";
}

int LoopStage::start()
{
	cout << "For the following loop, answer each question." << endl;
	Game::delay(100L);
	cout << "long x = 10;" << endl;
	cout << "long y = 20;" << endl;
	cout << "for (int i = 0; i < 10; i++)" << endl;
	cout << "{" << endl;
	cout << "    x *= (i + 1);" << endl;
	cout << "    y += i" << endl;
	cout << "}" << endl;
	cout << "long z = x + y;" << endl << endl;
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
			int score = 200 + (i * 200);
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

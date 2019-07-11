#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

Game::Game(string name, int totalStages)
{
	this->name = name;
	this->totalStages = totalStages;
	this->currentStage = 0;
	this->stageCount = 0;
	this->stages = new Stage*[totalStages];
	this->score = 0;

	for (unsigned int i = 0; i < this->name.length(); i++)
	{
		cout << this->name.at(i);
		cout.flush();
		delay(250);
	}

	cout << endl;
}

void Game::delay(unsigned long milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Game::trimString(string& str)
{
	while (isspace(str.at(0)))
	{
		str = str.substr(1, str.length());
	}

	while (isspace(str.at(str.length() - 1)))
	{
		str = str.substr(0, str.length() - 1);
	}
}

void Game::lowercase(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str.at(i) = tolower(str.at(i));
	}
}

bool Game::initialized()
{
	for (int i = 0; i < totalStages; i++)
	{
		if (stages[i] == nullptr)
		{
			return false;
		}
	}

	return true;
}

void Game::addStage(Stage* stage)
{
	if (stageCount >= totalStages)
	{
		return;
	}

	stages[stageCount++] = stage;
}

string Game::getName()
{
	return name;
}

void Game::begin()
{
	if (totalStages == 0 || !initialized())
	{
		return;
	}

	Stage* stage = nullptr;

	do
	{
		stage = stages[currentStage];
		cout << endl << "Beginning Stage " << (currentStage + 1) << " out of " << totalStages << "!" << endl;
		cout << '*' << stage->getName() << '*' << endl;
		score += stage->start();
		cout << "Completed Stage " << (currentStage + 1) << " out of " << totalStages << "!" << endl;
		currentStage++;
	}
	while (currentStage < totalStages);

	cout << endl << "Your overall score: " << score << endl;
}

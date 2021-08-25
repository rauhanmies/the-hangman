#pragma once
#include <string>

using namespace std;

class Launcher
{
private:
	int wrongAnswer;
	int maxAnswers;
	

public:
	Launcher();
	void Start();
	void PrintGameInfo();
	void PrintGallow();
	char GetAnswer();
	void GameValidator();
	void GameMenu();
	void QuitProgram();
	string FileReader();
};
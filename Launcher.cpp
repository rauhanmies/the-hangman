#include "Launcher.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Launcher::Launcher()
{
	// empty for now, add functionality if needed
}

void Launcher::Start()
{
		GameMenu();
}

void Launcher::PrintGameInfo()
{
	cout << "**********************************************************" << endl;
	cout << "Try to guess word by giving a character" << endl;
	cout << "**********************************************************" << endl;
}

string Launcher::FileReader()
{
	// variable for random word
	string word;
	vector<string> lines;
	srand((unsigned)time(0));

	cout << "Choose theme for words" << endl;
	cout << "**********************************************************" << endl;
	cout << "1. Alcohols" << endl;
	cout << "2. Cars" << endl;
	cout << "3. Countries" << endl;

	char wordListAnswer = GetAnswer();

	if (wordListAnswer == '1')
	{
		ifstream file("WordListAlcohol.txt");
		int total_lines = 0;
		while (getline(file, word))
		{
			total_lines++;
			lines.push_back(word);
		}

		int randomNumber = rand() % total_lines;

		file.close();
		word = lines[randomNumber];

		cout << "Alcohols chosen" << endl;
	}

	else if (wordListAnswer == '2')
	{
		ifstream file("WordListCars.txt");
		int total_lines = 0;
		while (getline(file, word))
		{
			total_lines++;
			lines.push_back(word);
		}

		int randomNumber = rand() % total_lines;

		file.close();
		word = lines[randomNumber];

		cout << "Cars chosen" << endl;
	}
	else if (wordListAnswer == '3')
	{
		ifstream file("WordListCountries.txt");
		int total_lines = 0;
		while (getline(file, word))
		{
			total_lines++;
			lines.push_back(word);
		}

		int randomNumber = rand() % total_lines;

		file.close();
		word = lines[randomNumber];

		cout << "Countries chosen" << endl;
	}
	else
	{
		cout << "Check your typing" << endl;
		GameValidator();
	}

	return word;
}

void Launcher::PrintGallow()
{
	// some eye candy
	if (wrongAnswer == 0)
	{
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "                         -------                          " << endl;
		cout << "**********************************************************" << endl;
	}

	if (wrongAnswer == 1)
	{
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                         -------                          " << endl;
		cout << "**********************************************************" << endl;
	}

	if (wrongAnswer == 2)
	{
		cout << "" << endl;
		cout << "" << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                         -------                          " << endl;
		cout << "**********************************************************" << endl;
	}

	if (wrongAnswer == 3)
	{
		cout << "" << endl;
		cout << "                          |/                              " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                         -------                          " << endl;
		cout << "**********************************************************" << endl;
	}

	if (wrongAnswer == 4)
	{
		cout << "                          _____                           " << endl;
		cout << "                          |/  |                           " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                          |                               " << endl;
		cout << "                         -------                          " << endl;
		cout << "**********************************************************" << endl;
	}

	if (wrongAnswer == 5)
	{
		cout << "                          _____                           " << endl;
		cout << "                          |/  |                           " << endl;
		cout << "                          |   O                           " << endl;
		cout << "                          |   M                           " << endl;
		cout << "                          |   |                           " << endl;
		cout << "                          |                               " << endl;
		cout << "                         -------                          " << endl;
		cout << "**********************************************************" << endl;
	}

}

char Launcher::GetAnswer()
{
	// this handles user input
	cout << ">";
	char userInput;
	cin >> userInput;

	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');

	return toupper(userInput);
}

void Launcher::GameValidator()
{
	wrongAnswer = 0;
	maxAnswers = 5;
	
	// use FileReader() to assign word
	string word = FileReader();
	// make word unreadable
	string random(word.length(), '*');

	PrintGameInfo();

	// loop for game instance
	while (wrongAnswer < maxAnswers)
	{

		PrintGallow();

		// shows user number of tries left
		if (wrongAnswer <= 3)
		{
			cout << "Quess word: " << random << " You have " << maxAnswers - wrongAnswer << " tries left" << endl;
			cout << "**********************************************************" << endl;
		}
		else
		{
			cout << "Quess word: " << random << " This is your LAST chance!" << endl;
			cout << "**********************************************************" << endl;
		}

		// ask user input as guess
		char guess = GetAnswer();

		// checks if user input is found within the word
		bool charFound = false;
		// make character array of selected word
		const char* charArray = word.c_str();

		for (int i = 0; i < strlen(charArray); i++) {

			if (charArray[i] == guess)
			{
				charFound = true;
				random[i] = guess;
			}

		}

		// run if char is found within word
		if (charFound == true)
		{
			cout << "Very good!" << endl;
		}

		// run if char is not found within word
		if (charFound == false)
		{
			wrongAnswer++;
			cout << "That's wrong.." << endl;
		}

		// run if user guesses right word
		if (random == word)
		{
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "                            O                             " << endl;
			cout << "                           -V-                            " << endl;
			cout << "                            |                             " << endl;
			cout << "                         -------                          " << endl;
			cout << "**********************************************************" << endl;
			cout << "You got it! The word is " << word << ".. Enjoy life!" << endl;
			cout << "**********************************************************" << endl;

			break;
		}

		// run if user is out of tries
		if (wrongAnswer == maxAnswers)
		{
			PrintGallow();
			cout << "Out of luck. You have been hanged.. The word was " << word << endl;
			cout << "**********************************************************" << endl;

			break;
		}

	}
	GameMenu();
}

void Launcher::GameMenu()
{
	cout << "Hangman game by Tuomas Markkanen" << endl;
	cout << "**********************************************************" << endl;
	cout << "1. Start new game." << endl;
	cout << "2. Quit program." << endl;

	char menuAnswer = GetAnswer();

	if (menuAnswer == '1')
	{
		GameValidator();
	}
	else
	{
		QuitProgram();
	}

}


void Launcher::QuitProgram()
{
	cout << "********************************************" << endl;
	cout << "Thank you for playing!" << endl;
	cout << "********************************************" << endl;
}
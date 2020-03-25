// ZORK.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <vector>
#include <iostream>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>

#include "World.h"
#include "Global.h"

using namespace std;
bool gameOver;
bool victory;

int main()
{

	char key;
    string input;
    vector<string> tokens;
	gameOver = false;
	victory = false;

    cout << "Welcome to Xesk's Zork!\n";
    cout << "----------------\n";

    World world;

	tokens.push_back("look");

    while (!gameOver) {
		if (_kbhit() != 0)
		{
			key = _getch();
			if (key == '\b') // backspace
			{
				if (input.length() > 0)
				{
					input.pop_back();
					cout << '\b'; // erase last character
					cout << " ";
					cout << '\b';
				}
			}
			else if (key != '\r') // any other key, NOT return
			{
				input += key;
				cout << key;
			}
			else {	// when return, create tokens
				Tokenize(input, tokens);
				cout << endl << endl;
			}
		}

		if (tokens.size() > 0 && Same(tokens[0], "quit"))
			break;

		if (world.Parser(tokens) == false)
			cout << "((Sorry, I do not understand your command.))" << endl;

		if (tokens.size() > 0)
		{
			tokens.clear();
			input = "";
			cout << "> ";
		}
    }

	
	if (victory) {
		using namespace std::this_thread;	// sleep_for
		using namespace std::chrono;		// nanoseconds
		sleep_for(seconds(4));
		cout << "\n\nCONGRATULATIONS!\nYou retrieved the ancient Amulet of Molag Bal.\n"
			"You start thinking how you will use its power to conquer the world as you extend\n"
			"your wings, and jump through the ledge to..." << endl << endl;
		sleep_for(seconds(4));
		cout << "..." << endl << endl;
		sleep_for(seconds(1));
		cout << "What...? You thought you were human?" << endl << endl;
		sleep_for(seconds(1));
		cout << "------------------------------------" << endl;
		cout << "GAME OVER - YOU WON!" << endl;
	}

    return 0;

}


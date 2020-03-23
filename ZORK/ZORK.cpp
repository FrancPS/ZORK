// ZORK.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <vector>
#include <iostream>
#include <conio.h>
#include <string> 

#include "World.h"
#include "Global.h"
#include "ZORK.h"

using namespace std;

int main()
{

	char key;
    string input;
    vector<string> tokens;

    cout << "Welcome to Xesk's Zork!\n";
    cout << "----------------\n";

    World world;

	tokens.push_back("look");

    while (1) {
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

    system("pause");
    return 0;

}


#include "Global.h"

// ---- SAME ---
/* Compares two strings without case sensitivity.
	Returns TRUE if the strings are the same, false if not.

	Parameters:
		- String
		- String
	Return:
		- Boolean
*/
const bool Same(const string& a, const string& b)
{
	return _stricmp(a.c_str(), b.c_str()) == 0;
}

// ---- TOKENIZE ---
/* Reads a string of characters, and transforms each word into a token.
	A token is a single string without spaces.
	After creating a token, it stores it on a vector and this vector will be
	used later to interpret the commands written in the console.

	Parameters:
		- String
		- Vector of Strings
	Return:
		- NONE
*/
void Tokenize(const string& line, vector<string>& tokens)
{
	const char* str = line.c_str(); // cursor on the beginning of the string

	// read until the string ends
	do
	{
		const char* begin = str;

		while (*str != ' ' && *str) // if the character is not a whitespace, keep reading
			str++;

		tokens.push_back(string(begin, str)); // append the characters from begin to str positions, as a single string
	} while (0 != *str++);
}

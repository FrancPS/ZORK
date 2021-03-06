#ifndef __Global__
#define __Global__

#include <string>
#include <vector>

using namespace std;

// Methods
const bool Same(const string& a, const string& b);
void Tokenize(const string& line, vector<string>& arguments);

extern bool gameOver;
extern bool victory;
#endif //__Global__
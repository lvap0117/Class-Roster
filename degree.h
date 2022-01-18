#pragma once
#include <string>
using namespace std;


//C. The section where defining enumerated data type "Degree Program" occurs, these include: NETWORK, SECURITY, and SOFTWARE, as value types.

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };
static const string degreeProgramStrings[] = { "SECURITY","NETWORK","SOFTWARE" };
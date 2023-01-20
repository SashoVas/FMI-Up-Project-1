#include <iostream>
#include "Common.h"

bool DefineDeckardLine(
	double a,
	double b,
	const char name[],
	double lines[][2],
	char linesNames[][MaxNameLength],
	int currentLine) {
	if (name[0]=='\0')
	{
		std::cout << "Invalid Name" << std::endl;
		return false;
	}
	if (NameExist(name, linesNames, currentLine))
	{
		std::cout << "Name Exists" << std::endl;
		return false;
	}
	lines[currentLine][0] = a;
	lines[currentLine][1] = b;
	int currentLetter = 0;
	PasteTo(name, linesNames[currentLine]);
	std::cout << "Line: " << name << " is defined" << std::endl;
	return true;
}
bool DefineLine(double a,
	double b,
	double c,
	const char name[],
	double lines[][2],
	char linesNames[][MaxNameLength],
	int currentLine,
	bool notFunctions[]) {
	if (NameExist(name, linesNames, currentLine))
	{
		std::cout << "Name Exists" << std::endl;
		return false;
	}
	if (a == 0)
	{
		bool isDefined=DefineDeckardLine(0, c / b, name, lines, linesNames, currentLine);
		notFunctions[currentLine] = isDefined;
		return isDefined;
	}
	else
	{
		return DefineDeckardLine(b / a, c / a, name, lines, linesNames, currentLine);
	}
}
void PrintLine(const double line[], const char lineName[MaxNameLength], char leftSide = 'y', char rightSide = 'x') {
	bool zeroFirst = false;
	std::cout << "Line " << lineName << ":" << leftSide << "=";
	if (line[0] == 0)
	{
		zeroFirst = true;
	}
	else if (line[0] == 1)
	{
		std::cout << rightSide << " ";

	}
	else if (line[0] == -1)
	{
		std::cout << "-" << rightSide << " ";
	}
	else
	{
		std::cout << line[0] << rightSide << " ";
	}

	if (line[1] == 0)
	{
		if (zeroFirst)
		{
			std::cout << 0;
		}
	}
	else if (line[1] > 0 && !zeroFirst)
	{

		std::cout << "+" << line[1];

	}
	else
	{
		std::cout << line[1];

	}
}
void ListLines(const double lines[][2], const char linesNames[][MaxNameLength], int currentLine, const bool notFunctions[]) {
	std::cout << "Lines:" << std::endl;
	for (int i = 0; i < currentLine; i++)
	{
		if (notFunctions[i])
		{
			PrintLine(lines[i], linesNames[i], 'x', 'y');
		}
		else
		{
			PrintLine(lines[i], linesNames[i]);
		}

		std::cout << std::endl;
	}
}
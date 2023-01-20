#pragma once
#include <iostream>
bool DefineDeckardLine(double a, double b, const char name[], double lines[][2], char linesNames[][MaxNameLength], int currentLine);
bool DefineLine(double a,
	double b,
	double c,
	const char name[],
	double lines[][2],
	char linesNames[][MaxNameLength],
	int currentLine,
	bool notFunctions[]);
void ListLines(const double lines[][2], const char linesNames[][MaxNameLength], int currentLine, const bool notFunctions[]);
void PrintLine(const double line[], const char lineName[MaxNameLength], char leftSide = 'y', char rightSide = 'x');
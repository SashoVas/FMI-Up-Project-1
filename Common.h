#pragma once
#include <iostream>
const double Epsilon = 0.0000001;
const int MaxNameLength = 100;
bool AreNamesEqual(const char name1[], const char name2[]);
int FindIndex(const char name[], const char names[][100], int namesCount);
bool NameExist(const char name[], const char namesArr[][100], int namesCount);
double GetValueOfALineAtAPoint(const double line[2], double pointX);
bool GetLineByTwoPoints(const double point1[2], const double point2[2], double line[2]);
void PasteTo(const char from[],char to[]);
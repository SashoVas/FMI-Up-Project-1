#include <iostream>
bool AreNamesEqual(const char name1[], const char name2[]) {
	int index = 0;
	while (name1[index] != '\0' && name2[index] != '\0')
	{
		if (name1[index] != name2[index])
		{
			return false;
		}
		index++;
	}
	if (name1[index] != name2[index])
	{
		return false;
	}
	return true;
}
int FindIndex(const char name[], const char names[][100], int namesCount) {
	for (int i = 0; i < namesCount; i++)
	{
		if (AreNamesEqual(name, names[i]))
		{
			return i;
		}
	}
	return -1;
}
bool NameExist(const char name[], const char namesArr[][100], int namesCount) {
	int nameIndex = FindIndex(name, namesArr, namesCount);
	if (nameIndex == -1)
	{
		return false;
	}
	return true;
}
double GetValueOfALineAtAPoint(const double line[2], double pointX) {
	return line[0] * pointX + line[1];
}
bool GetLineByTwoPoints(const double point1[2], const double point2[2],double line[2]) {
	const double Epsilon = 0.0000001;
	double diff = (point1[0] - point2[0]);
	if (diff > -Epsilon && diff < Epsilon)
	{
		line[0] = 0;
		line[1] = point1[0];
		return false;
	}
	double a = (point1[1] - point2[1]) / diff;
	double b = (point1[1] - a * point1[0]);

	line[0] = a;
	line[1] = b;
	return true;
}
void PasteTo(const char from[], char to[]) {
	int current = 0;
	while (from[current]!='\0')
	{
		to[current] = from[current];
		current++;
	}
	to[current] = from[current];
}
#include "Common.h"
bool DefinePoint(double a, double b, const char name[], double points[][2], char pointsNames[][MaxNameLength], int currentPoint) {
	if (NameExist(name, pointsNames, currentPoint))
	{
		std::cout << "Name Exists" << std::endl;
		return false;
	}
	points[currentPoint][0] = a;
	points[currentPoint][1] = b;
	int currentLetter = 0;
	PasteTo(name, pointsNames[currentPoint]);
	std::cout << "Point: " << name << " is defined" << std::endl;
	return true;
}
void ListPoints(const double points[][2], const char pointsNames[][MaxNameLength], int currentPoint) {
	std::cout << "Points:" << std::endl;
	for (int i = 0; i < currentPoint; i++)
	{
		std::cout << "Point " << pointsNames[i] << ":(" << points[i][0] << "," << points[i][1] << ")" << std::endl;
	}
}
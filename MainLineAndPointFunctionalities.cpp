#include <iostream>
#include "Common.h"
#include "LineFunctionalities.h"

bool IsPointOnTheLine(
	const char pointName[],
	const char lineName[],
	const double points[][2],
	const double lines[][2],
	const char pointsNames[][MaxNameLength],
	const char linesNames[][MaxNameLength],
	int pointsCount,
	int linesCount,
	const bool notFunctions[]) {

	int pointIndex = FindIndex(pointName, pointsNames, pointsCount);
	int lineIndex = FindIndex(lineName, linesNames, linesCount);
	if (pointIndex == -1 || lineIndex == -1)
	{
		std::cout << "Invalid names" << std::endl;
		return false;
	}
	double pointX = points[pointIndex][0];
	double pointY = points[pointIndex][1];
	double lineA = lines[lineIndex][0];
	double lineB = lines[lineIndex][1];
	if (notFunctions[lineIndex])
	{
		double dif = pointX - lineB;
		return dif > -Epsilon && dif < Epsilon;
	}
	double result = pointX * lineA + lineB;
	double differance = pointY - result;

	return differance > -Epsilon && differance < Epsilon;
}
void PrintTheParallel(
	const char pointName[],
	const char lineName[],
	const double points[][2],
	const double lines[][2],
	const char pointsNames[][MaxNameLength],
	const char linesNames[][MaxNameLength],
	int pointsCount,
	int linesCount) {

	int pointIndex = FindIndex(pointName, pointsNames, pointsCount);
	int lineIndex = FindIndex(lineName, linesNames, linesCount);
	if (pointIndex == -1 || lineIndex == -1)
	{
		std::cout << "Invalid names" << std::endl;
		return;
	}
	double newLine[] = { 0,0 };
	newLine[0] = lines[lineIndex][0];
	newLine[1] = lines[lineIndex][1] - (GetValueOfALineAtAPoint(lines[lineIndex], points[pointIndex][0]) - points[pointIndex][1]);
	std::cout << "The parallel in point " << pointName << " of the ";
	PrintLine(newLine, lineName);
	std::cout << std::endl;
}
bool GetIntersectionWhenNotFunctions(
	const double line1[],
	const double line2[],
	double destination[],
	bool isNotFunction1,
	bool isNotFunction2) {
	if (isNotFunction1 && isNotFunction2)
	{
		if (line1[1] == line2[1])
		{
			std::cout << "The lines are identical" << std::endl;
			return false;
		}
		std::cout << "The lines are parallel so there is no intersection" << std::endl;
		return false;
	}
	else if (isNotFunction1)
	{
		destination[0] = line1[1];
		destination[1] = GetValueOfALineAtAPoint(line2, line1[1]);
		return true;
	}
	else if (isNotFunction2)
	{
		destination[0] = line2[1];
		destination[1] = GetValueOfALineAtAPoint(line1, line2[1]);
		return true;
	}
}
bool GetIntersection(
	const double line1[],
	const double line2[],
	double destination[],
	bool isNotFunction1,
	bool isNotFunction2) {
	if (isNotFunction1||isNotFunction2)
	{
		return GetIntersectionWhenNotFunctions(line1,line2,destination,isNotFunction1,isNotFunction2);
	}
	if (line1[0] == line2[0])
	{
		if (line1[1] == line2[1])
		{
			std::cout << "The lines are identical" << std::endl;
		}
		else
		{
			std::cout << "The lines are parallel so there is no intersection" << std::endl;
		}
		return false;
	}
	destination[0] = (line2[1] - line1[1]) / (line1[0] - line2[0]);
	destination[1] = GetValueOfALineAtAPoint(line1, destination[0]);
	return true;
}
void PrintTheIntersection(
	const char lineName1[],
	const char lineName2[],
	const double lines[][2],
	const char linesNames[][MaxNameLength],
	int linesCount,
	const bool notFuction[]) {
	int line1Index = FindIndex(lineName1, linesNames, linesCount);
	int line2Index = FindIndex(lineName2, linesNames, linesCount);
	if (line1Index == -1 || line2Index == -1)
	{
		std::cout << "Invalid names" << std::endl;
		return;
	}
	double point[2];
	if (!GetIntersection(lines[line1Index], lines[line2Index],point,notFuction[line1Index],notFuction[line2Index]))
	{
		return;
	}
	std::cout << "The intersection is in point: (" << point[0] << "," << point[1] << ")" << std::endl;
}
void PrintThePerpendicularThroughAPoint(
	const double line[2],
	const double point[2],
	const char lineName[],
	bool notFunction) {
	double newLine[] = { 0,0 };
	if (notFunction)
	{
		std::cout << "The perpendicular in point (" << point[0] << "," << point[1] << ") of the " << lineName << ": y=" << point[1];
	}
	else if (line[0]<Epsilon && line[0]>-Epsilon)
	{
		std::cout << "The perpendicular in point (" << point[0] << "," << point[1] << ") of the " << lineName << ": x=" << point[0];
	}
	else
	{
		newLine[0] = -1 / line[0];
		newLine[1] = -(GetValueOfALineAtAPoint(newLine, point[0]) - point[1]);
		std::cout << "The perpendicular in point (" << point[0] << "," << point[1] << ") of the ";
		PrintLine(newLine, lineName);
	}

	std::cout << std::endl;
}
void PrintThePerpendicular(
	const char pointName[],
	const char lineName[],
	const double points[][2],
	const double lines[][2],
	const char pointsNames[][MaxNameLength],
	const char linesNames[][MaxNameLength],
	int pointsCount,
	int linesCount,
	const bool notFunctions[]) {
	if (!IsPointOnTheLine(pointName, lineName, points, lines, pointsNames, linesNames, pointsCount, linesCount, notFunctions))
	{
		std::cout << "The point is not on the line" << std::endl;
		return;
	}

	int pointIndex = FindIndex(pointName, pointsNames, pointsCount);
	int lineIndex = FindIndex(lineName, linesNames, linesCount);
	if (pointIndex == -1 || lineIndex == -1)
	{
		std::cout << "Invalid names" << std::endl;
		return;
	}
	PrintThePerpendicularThroughAPoint(lines[lineIndex], points[pointIndex], lineName, notFunctions[lineIndex]);

}
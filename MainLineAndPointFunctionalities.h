#pragma once
#include <iostream>
bool IsPointOnTheLine(
	const char pointName[],
	const char lineName[],
	const double points[][2],
	const double lines[][2],
	const char pointsNames[][MaxNameLength],
	const char linesNames[][MaxNameLength],
	int pointsCount,
	int linesCount,
	const bool notFunctions[]);
void PrintTheParallel(
	const char pointName[],
	const char lineName[],
	const double points[][2],
	const double lines[][2], 
	const char pointsNames[][MaxNameLength],
	const char linesNames[][MaxNameLength],
	int pointsCount,
	int linesCount);
void PrintTheIntersection(
	const char lineName1[],
	const char lineName2[],
	const double lines[][2],
	const char linesNames[][MaxNameLength],
	int linesCount,
	const bool notFuction[]);
void PrintThePerpendicularThroughAPoint(
	const double line[2],
	const double point[2],
	const char lineName[],
	bool notFunction);
void PrintThePerpendicular(
	const char pointName[],
	const char lineName[],
	const double points[][2], 
	const double lines[][2], 
	const char pointsNames[][MaxNameLength],
	const char linesNames[][MaxNameLength],
	int pointsCount,
	int linesCount,
	const bool notFunctions[]);
bool GetIntersection(
	const double line1[],
	const double line2[],
	double destination[],
	bool isNotFunction1,
	bool isNotFunction2);
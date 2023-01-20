#pragma once
#include <iostream>
void PrintTriangleInfo(
	const char point1Name[],
	const char point2Name[],
	const char point3Name[],
	const double points[][2],
	const char pointsNames[][MaxNameLength],
	int pointsCount);
void PrintEquationOfTangent(double a, double b, double c, double pointX);
void PrintTheIntersectionOfParabolaAndALine(
	double a,
	double b,
	double c,
	const char lineName[],
	const double lines[][2],
	const char linesNames[][MaxNameLength],
	int linesCount);
int GetSquareType(
	const double line1[2],
	const double line2[2],
	const double line3[2],
	const double line4[2],
	int line1Index,
	int line2Index,
	int line3Index,
	int line4Index,
	const bool notFunctions[]);
void PrintSquareInfo(
	const char lineName1[],
	const char lineName2[],
	const char lineName3[],
	const char lineName4[],
	const double lines[][2],
	const char linesNames[][MaxNameLength],
	int linesCount,
	const bool notFunctions[]);

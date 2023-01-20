#include <iostream>
#include "Common.h"
#include "MainLineAndPointFunctionalities.h"
#include "LineFunctionalities.h"
const int SquareId = 1;
const int RectangleId = 2;
const int RhombusId = 3;
const int ParallelogramId = 4;
const int TrapezoidId = 5;
const int QuadrilateralId = 6;

void PrintTriangleInfo(
	const char point1Name[],
	const char point2Name[],
	const char point3Name[],
	const double points[][2],
	const char pointsNames[][MaxNameLength],
	int pointsCount) {
	int point1Index = FindIndex(point1Name, pointsNames, pointsCount);
	int point2Index = FindIndex(point2Name, pointsNames, pointsCount);
	int point3Index = FindIndex(point3Name, pointsNames, pointsCount);
	if (point1Index == -1 || point2Index == -1 || point3Index == -1)
	{
		std::cout << "Invalid names" << std::endl;
		return;
	}
	double line1[] = { 0,0 };
	double line2[] = { 0,0 };
	double line3[] = { 0,0 };
	double line1Middle[] = { (points[point1Index][0] + points[point2Index][0]) / 2,(points[point1Index][1] + points[point2Index][1]) / 2 };
	double line2Middle[] = { (points[point1Index][0] + points[point3Index][0]) / 2,(points[point1Index][1] + points[point3Index][1]) / 2 };
	double line3Middle[] = { (points[point3Index][0] + points[point2Index][0]) / 2,(points[point3Index][1] + points[point2Index][1]) / 2 };
	const char line1Name[] = "a";
	const char line2Name[] = "b";
	const char line3Name[] = "c";

	bool isLine1Function = GetLineByTwoPoints(points[point1Index], points[point2Index], line1);
	bool isLine2Function = GetLineByTwoPoints(points[point1Index], points[point3Index], line2);
	bool isLine3Function = GetLineByTwoPoints(points[point3Index], points[point2Index], line3);

	std::cout << "Medians" << std::endl;
	double median1[2];
	bool isMedian1Function = GetLineByTwoPoints(points[point1Index], line3Middle, median1);
	double median2[2];
	bool isMedian2Function = GetLineByTwoPoints(points[point2Index], line2Middle, median2);
	double median3[2];
	bool isMedian3Function = GetLineByTwoPoints(points[point3Index], line1Middle, median3);
	const char median1Name[] = "median1";
	const char median2Name[] = "median2";
	const char median3Name[] = "median3";
	PrintLine(median1, median1Name, !isMedian1Function ? 'x' : 'y');
	std::cout << std::endl;
	PrintLine(median2, median2Name, !isMedian2Function ? 'x' : 'y');
	std::cout << std::endl;
	PrintLine(median3, median3Name, !isMedian3Function ? 'x' : 'y');
	std::cout << std::endl;
	std::cout << "Heights" << std::endl;

	PrintThePerpendicularThroughAPoint(line1, points[point3Index], line1Name, !isLine3Function);
	PrintThePerpendicularThroughAPoint(line2, points[point2Index], line2Name, !isLine2Function);
	PrintThePerpendicularThroughAPoint(line3, points[point1Index], line3Name, !isLine1Function);

	std::cout << "Bisector" << std::endl;

	PrintThePerpendicularThroughAPoint(line1, line1Middle, line1Name, !isLine1Function);
	PrintThePerpendicularThroughAPoint(line2, line2Middle, line2Name, !isLine2Function);
	PrintThePerpendicularThroughAPoint(line3, line3Middle, line3Name, !isLine3Function);
}
void PrintEquationOfTangent(double a, double b, double c, double pointX) {
	double derivativeA = a * 2;
	double derivativeB = b;
	double functionalValueAtX = a * (pointX * pointX) + b * pointX + c;
	double functionalValueOfDerivativeAtX = derivativeA * pointX + derivativeB;
	double line[] = { functionalValueOfDerivativeAtX,functionalValueAtX - functionalValueOfDerivativeAtX * pointX };
	std::cout << "The tangent of the parabola is the ";
	char name[] = "";
	PrintLine(line, name);
	std::cout << std::endl;
}
void PrintTheIntersectionOfParabolaAndALine(
	double a,
	double b,
	double c,
	const char lineName[],
	const double lines[][2], 
	const char linesNames[][MaxNameLength],
	int linesCount) {
	int lineIndex = FindIndex(lineName, linesNames, linesCount);
	if (lineIndex == -1)
	{
		std::cout << "Invalid names" << std::endl;
		return;
	}
	b -= lines[lineIndex][0];
	c -= lines[lineIndex][1];
	double D = b * b - 4 * a * c;
	if (D < 0)
	{
		std::cout << "No intersections" << std::endl;
		return;
	}
	double x1 = (-b + sqrt(D)) / 2 * a;
	double x2 = (-b - sqrt(D)) / 2 * a;
	if (D > -Epsilon && D < Epsilon)
	{
		std::cout << "There is one intersection in point(" << x1 << "," << GetValueOfALineAtAPoint(lines[lineIndex], x1) << ")" << std::endl;
	}
	else
	{
		std::cout << "There are two intersections in point(" << x1 << "," << GetValueOfALineAtAPoint(lines[lineIndex], x1) << ")" << "and in point(" << x2 << "," << GetValueOfALineAtAPoint(lines[lineIndex], x2) << ")" << std::endl;
	}
}
double GetDistanceBetweenPoints(const double point1[], const double point2[])
{
	return sqrt((point2[0] - point1[0]) * (point2[0] - point1[0]) + (point2[1] - point1[1])* (point2[1] - point1[1]));
}
bool AreSidesEqual(
	const double line1[2],
	const double line2[2],
	const double line3[2],
	const double line4[2],
	bool line1NotFunction,
	bool line2NotFunction,
	bool line3NotFunction,
	bool line4NotFunction) {
	double a[2];
	double b[2];
	double c[2];
	double d[2];
	GetIntersection(line1,line2,a, line1NotFunction, line2NotFunction);
	GetIntersection(line1,line4,d, line1NotFunction, line4NotFunction);
	GetIntersection(line3,line2,b, line3NotFunction, line2NotFunction);
	GetIntersection(line3,line4,c, line3NotFunction, line4NotFunction);
	double ab = GetDistanceBetweenPoints(a,b);
	double da = GetDistanceBetweenPoints(d,a);
	double bc = GetDistanceBetweenPoints(b,c);
	double cd = GetDistanceBetweenPoints(c,d);
	return ab - cd>-Epsilon&& ab - cd<Epsilon && da - bc>-Epsilon&& da - bc<Epsilon;
}
int GetSquareType(
	const double line1[2],
	const double line2[2],
	const double line3[2],
	const double line4[2],
	int line1Index,
	int line2Index,
	int line3Index,
	int line4Index,
	const bool notFunctions[]) {
	if (line1[0] == line3[0] && notFunctions[line1Index] == notFunctions[line3Index])
	{
		if (line2[0] == line4[0] && notFunctions[line1Index] == notFunctions[line3Index])
		{
			double differance = (-1 / (line2[0])) - line1[0];
			if (line2[0]<Epsilon && line2[0]>-Epsilon && line1[0]<Epsilon && line1[0]>-Epsilon && notFunctions[line2Index] != notFunctions[line1Index])
			{
				differance = 0;
			}
			if (differance > -Epsilon && differance < Epsilon)
			{
				if (AreSidesEqual(line1,line2,line3,line4, notFunctions[line1Index], notFunctions[line2Index], notFunctions[line3Index], notFunctions[line4Index]))
				{
					return SquareId;
				}
				return RectangleId;
			}
			else
			{
				if (AreSidesEqual(line1, line2, line3, line4, notFunctions[line1Index], notFunctions[line2Index], notFunctions[line3Index], notFunctions[line4Index]))
				{
					return RhombusId;
				}
				return ParallelogramId;
			}
		}
		else
		{
			return TrapezoidId;
		}
	}
	else if (line2[0] == line4[0] && notFunctions[line2Index] == notFunctions[line4Index])
	{
		return TrapezoidId;
	}
	else
	{
		return QuadrilateralId;
	}
}
void PrintSquareInfo(
	const char lineName1[],
	const char lineName2[],
	const char lineName3[],
	const char lineName4[],
	const double lines[][2],
	const char linesNames[][MaxNameLength],
	int linesCount,
	const bool notFunctions[]) {
	int line1Index = FindIndex(lineName1, linesNames, linesCount);
	int line2Index = FindIndex(lineName2, linesNames, linesCount);
	int line3Index = FindIndex(lineName3, linesNames, linesCount);
	int line4Index = FindIndex(lineName4, linesNames, linesCount);
	if (line1Index == -1 || line2Index == -1 || line3Index == -1 || line4Index == -1)
	{
		std::cout << "Invalid names" << std::endl;
		return;
	}
	if (line1Index == line2Index || line1Index == line3Index || line1Index == line4Index || line2Index == line3Index || line2Index == line4Index || line3Index == line4Index)
	{
		std::cout << "You have to give 4 different lines" << std::endl;
		return;
	}
	double line1[2] = { lines[line1Index][0],lines[line1Index][1] };
	double line2[2] = { lines[line2Index][0],lines[line2Index][1] };
	double line3[2] = { lines[line3Index][0],lines[line3Index][1] };
	double line4[2] = { lines[line4Index][0],lines[line4Index][1] };

	int combination1 = GetSquareType(line1, line2, line3, line4, line1Index, line2Index, line3Index, line4Index, notFunctions);
	int combination2 = GetSquareType(line2, line1, line3, line4, line2Index, line1Index, line3Index, line4Index, notFunctions);
	int combination3 = GetSquareType(line3, line1, line4, line2, line3Index, line1Index, line4Index, line2Index, notFunctions);

	int squareType = combination1 < combination2 ? combination1 : combination2;
	squareType = squareType < combination3 ? squareType : combination3;
	switch (squareType)
	{
	case SquareId:
		std::cout << "Square" << std::endl;
		break;
	case RectangleId:
		std::cout << "Rectangle" << std::endl;
		break;
	case RhombusId:
		std::cout << "Rhombus" << std::endl;
		break;
	case ParallelogramId:
		std::cout << "Parallelogram" << std::endl;
		break;
	case TrapezoidId:
		std::cout << "Trapezoid" << std::endl;
		break;
	case QuadrilateralId:
		std::cout << "Quadrilateral" << std::endl;
		break;
	default:
		break;
	}
}
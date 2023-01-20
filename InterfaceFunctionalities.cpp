#include <iostream>
#include <cmath>
#include "Common.h"
#include "LineFunctionalities.h"
#include "PointFunctionalities.h"
#include "MainLineAndPointFunctionalities.h"
#include "ComplexShapeFunctionalities.h"
void PrintInstructions() {
	std::cout << "==================================================================================" << std::endl;
	std::cout << "1: Print Lines" << std::endl;
	std::cout << "2: Print Points" << std::endl;
	std::cout << "D: Define Deckard Line (y= ax+b) (a,b,name)" << std::endl;
	std::cout << "L: Define Line (ay+bx+c) (a,b,c,name)" << std::endl;
	std::cout << "P: Define Point (x,y), (x,y,name)" << std::endl;
	std::cout << "3: Is Point On The Line: (Line Name, Point Name)" << std::endl;
	std::cout << "4: Get Parallel Line Of A Line In A Point: (Line Name, Point Name)" << std::endl;
	std::cout << "5: Get Perpendicular Line Of A Line In A Point: (Line Name, Point Name)" << std::endl;
	std::cout << "6: Get Intersection Of Two Lines: (First Line Name, Second Line Name)" << std::endl;
	std::cout << "7: Get Triangle Info: (First Point Name, Second Point Name, Third Point Name)" << std::endl;
	std::cout << "8: Get Tangent Of Parabola: (a, b, c, x)" << std::endl;
	std::cout << "9: Get Intersection Of Parabola And A Line: (a, b, c, Line Name)" << std::endl;
	std::cout << "0: Get Rectangle Info: (First Point Name, Second Point Name, Third Point Name, Fourth Point Name)" << std::endl;
	std::cout << "C: Clear" << std::endl;
	std::cout << "X: Close" << std::endl;
	std::cout << "==================================================================================" << std::endl;
}
void Run() {
	const int MaxArraySize = 100;
	double points[MaxArraySize][2];
	double lines[MaxArraySize][2];
	char pointsNames[MaxArraySize][MaxNameLength];
	char linesNames[MaxArraySize][MaxNameLength];
	bool notFunctions[MaxArraySize] = { false };
	int currentPoint = 0;
	int currentLine = 0;
	char input=' ';
	PrintInstructions();
	while (input != 'X')
	{
		std::cout << "Choose operation:";
		std::cin >> input;
		if (input == '1')
		{
			ListLines(lines, linesNames, currentLine, notFunctions);
		}
		else if (input == '2')
		{
			ListPoints(points, pointsNames, currentPoint);
		}
		else if (input == 'L')
		{
			double a;
			double b;
			double c;
			char name[MaxNameLength];
			std::cin >> a >> b >> c >> name;
			if (DefineLine(a, b, c, name, lines, linesNames, currentLine, notFunctions))
			{
				currentLine++;
			}
		}
		else if (input == 'D')
		{
			double a;
			double b;
			char name[MaxNameLength];
			std::cin >> a >> b >> name;
			if (DefineDeckardLine(a, b, name, lines, linesNames, currentLine))
			{
				currentLine++;
			}
		}
		else if (input == 'P')
		{
			double a;
			double b;
			char name[MaxNameLength];
			std::cin >> a >> b >> name;
			if (DefinePoint(a, b, name, points, pointsNames, currentPoint))
			{
				currentPoint++;
			}
		}
		else if (input == '3')
		{
			char pointName[MaxNameLength];
			char lineName[MaxNameLength];
			std::cin >> lineName >> pointName;
			std::cout << (IsPointOnTheLine(pointName, lineName, points, lines, pointsNames, linesNames, currentPoint, currentLine, notFunctions) ? "Yes" : "No") << std::endl;
		}
		else if (input == '4')
		{
			char pointName[MaxNameLength];
			char lineName[MaxNameLength];
			std::cin >> lineName >> pointName;
			PrintTheParallel(pointName, lineName, points, lines, pointsNames, linesNames, currentPoint, currentLine);
		}
		else if (input == '5')
		{
			char pointName[MaxNameLength];
			char lineName[MaxNameLength];
			std::cin >> lineName >> pointName;
			PrintThePerpendicular(pointName, lineName, points, lines, pointsNames, linesNames, currentPoint, currentLine, notFunctions);
		}
		else if (input == '6')
		{
			char lineName1[MaxNameLength];
			char lineName2[MaxNameLength];
			std::cin >> lineName1 >> lineName2;
			PrintTheIntersection(lineName1, lineName2, lines, linesNames, currentLine, notFunctions);
		}
		else if (input == '7')
		{
			char point1Name[MaxNameLength];
			char point2Name[MaxNameLength];
			char point3Name[MaxNameLength];
			std::cin >> point1Name >> point2Name >> point3Name;
			PrintTriangleInfo(point1Name, point2Name, point3Name, points, pointsNames, currentPoint);
		}
		else if (input == '8')
		{
			double a = 0, b = 0, c = 0, pointX = 0;
			std::cin >> a >> b >> c >> pointX;
			PrintEquationOfTangent(a, b, c, pointX);
		}
		else if (input == '9')
		{
			int a = 0, b = 0, c = 0;
			char lineName[MaxNameLength];
			std::cin >> a >> b >> c >> lineName;
			PrintTheIntersectionOfParabolaAndALine(a, b, c, lineName, lines, linesNames, currentLine);
		}
		else if (input == '0')
		{
			char line1Name[MaxNameLength];
			char line2Name[MaxNameLength];
			char line3Name[MaxNameLength];
			char line4Name[MaxNameLength];
			std::cin >> line1Name >> line2Name >> line3Name >> line4Name;
			PrintSquareInfo(line1Name, line2Name, line3Name, line4Name, lines, linesNames, currentLine, notFunctions);
		}
		else if (input == 'C')
		{
			system("cls");
			PrintInstructions();
		}
		else if (input == 'X')
		{
			std::cout << "Execution Stopped" << std::endl;
		}
		else
		{
			std::cout << "Invalid Input" << std::endl;
		}
	}
}
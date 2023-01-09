#include <iostream>
#include <cmath>

const double Epsilon = 0.0000001;
void ListPoints(double points[][2],char pointsNames[][100], int currentPoint) {
	for (int i = 0; i < currentPoint; i++)
	{
		std::cout << "Point " << pointsNames[i] << ":(" << points[i][0] << "," << points[i][1] << ")"<<std::endl;
	}
}
void DefinePoint(double a, double b, char name[],double points[][2],char pointsNames[][100], int currentPoint) {
    points[currentPoint][0]=a;
    points[currentPoint][1]=b;
	int currentLetter = 0;
	strcpy_s(pointsNames[currentPoint], name);
}
void PrintLine(double line[], char lineName[100]) {
	bool zeroFirst = false;
	std::cout << "Line " << lineName << ": y=";
	if (line[0] == 0)
	{
		zeroFirst = true;
	}
	else if (line[0] == 1)
	{
		std::cout << "x ";

	}
	else if (line[0] == -1)
	{
		std::cout << "-x ";
	}
	else
	{
		std::cout << line[0] << "x ";
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
void ListLines(double lines[][2], char linesNames[][100], int currentLine) {
	for (int i = 0; i < currentLine; i++)
	{
		PrintLine(lines[i],linesNames[i]);
		std::cout << std::endl;
	}
}
void DefineLine(double a, double b, char name[], double lines[][2], char linesNames[][100], int currentLine) {
	lines[currentLine][0] = a;
	lines[currentLine][1] = b;
	int currentLetter = 0;
	strcpy_s(linesNames[currentLine], name);
}
bool AreNamesEqual(char name1[],char name2[]) {
	int index = 0;
	while (name1[index]!='\0' && name2[index]!='\0')
	{
		if (name1[index]!=name2[index])
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
int FindIndex(char name[],char names[][100],int namesCount) {
	for (int i = 0; i < namesCount; i++)
	{
		if (AreNamesEqual(name,names[i]))
		{
			return i;
		}
	}
	return -1;
}
bool IsPointOnTheLine(char pointName[], char lineName[], double points[][2], double lines[][2], char pointsNames[][100], char linesNames[][100], int pointsCount, int linesCount) {
	int pointIndex = FindIndex(pointName, pointsNames, pointsCount);
	int lineIndex = FindIndex(lineName, linesNames, linesCount);

	double pointX = points[pointIndex][0];
	double pointY = points[pointIndex][1];
	double lineA = lines[lineIndex][0];
	double lineB = lines[lineIndex][1];

	double result = pointX * lineA + lineB;
	double differance = pointY - result;

	return differance > -Epsilon && differance < Epsilon;
}
double GetValueOfALineAtAPoint(double line[2],double pointX) {
	return line[0] * pointX + line[1];
}
void PrintTheParallel(char pointName[],char lineName[], double points[][2], double lines[][2], char pointsNames[][100], char linesNames[][100], int pointsCount, int linesCount) {
	int pointIndex = FindIndex(pointName, pointsNames, pointsCount);
	int lineIndex = FindIndex(lineName, linesNames, linesCount);
	double newLine[] = { 0,0 };
	newLine[0] = lines[lineIndex][0];
	newLine[1] = lines[lineIndex][1] - (GetValueOfALineAtAPoint(lines[lineIndex], points[pointIndex][0]) - points[pointIndex][1]);
	std::cout << "The parallel in point " <<pointName<<" of the ";
	PrintLine(newLine, lineName);
	std::cout << std::endl;
}
void PrintTheIntersection(char lineName1[], char lineName2[], double lines[][2], char linesNames[][100], int linesCount) {
	int line1Index = FindIndex(lineName1, linesNames, linesCount);
	int line2Index = FindIndex(lineName2, linesNames, linesCount);
	if (lines[line1Index][0]==lines[line2Index][0])
	{
		if (lines[line1Index][1]==lines[line2Index][1])
		{
			std::cout << "The lines are identical"<<std::endl;
		}
		else
		{
			std::cout << "The lines are parallel so there is no intersection" << std::endl;
		}
		return;
	}
	double pointX = (lines[line2Index][1] - lines[line1Index][1]) / (lines[line1Index][0] - lines[line2Index][0]);
	double pointY = GetValueOfALineAtAPoint(lines[line1Index],pointX);

	std::cout << "The intersection is in point: (" << pointX << "," << pointY << ")" << std::endl;
}
void PrintThePerpendicularThroughAPoint(double line[2],double point[2],char lineName[]) {
	double newLine[] = { 0,0 };
	if (line[0]<Epsilon&&line[0]>-Epsilon)
	{
		std::cout << "The perpendicular in point (" << point[0] << "," << point[1] << ") of the "<<lineName<<": x="<<point[0];
	}
	else
	{
		newLine[0] = -1 / line[0];
		newLine[1] = -(GetValueOfALineAtAPoint(newLine, point[0]) - point[1]);
		std::cout << "The perpendicular in point (" <<point[0]<<","<<point[1]<< ") of the ";
		PrintLine(newLine, lineName);
	}
	
	std::cout << std::endl;
}
void PrintThePerpendicular(char pointName[], char lineName[], double points[][2], double lines[][2], char pointsNames[][100], char linesNames[][100], int pointsCount, int linesCount) {
	if (!IsPointOnTheLine(pointName,lineName, points, lines, pointsNames, linesNames, pointsCount, linesCount))
	{
		std::cout << "The point is not on the line"<<std::endl;
		return;
	}

	int pointIndex = FindIndex(pointName, pointsNames, pointsCount);
	int lineIndex = FindIndex(lineName, linesNames, linesCount);
	PrintThePerpendicularThroughAPoint(lines[lineIndex],points[pointIndex],lineName);

}
void GetLineByTwoPoints(double point1[2],double point2[2],double line[2]) {
	double a = (point1[1]-point2[1])/(point1[0]-point2[0]);
	double b = (point1[1]-a*point1[0]);
	
	line[0] = a;
	line[1] = b;
}
void PrintTriangleInfo(char point1Name[],char point2Name[], char point3Name[], double points[][2],  char pointsNames[][100], int pointsCount) {
	int point1Index = FindIndex(point1Name, pointsNames, pointsCount);
	int point2Index = FindIndex(point2Name, pointsNames, pointsCount);
	int point3Index = FindIndex(point3Name, pointsNames, pointsCount);

	double line1[] = { 0,0 };
	double line2[] = { 0,0 };
	double line3[] = { 0,0 };
	double line1Middle[] = { (points[point1Index][0] + points[point2Index][0]) / 2,(points[point1Index][1] + points[point2Index][1]) / 2 };
	double line2Middle[] = { (points[point1Index][0] + points[point3Index][0]) / 2,(points[point1Index][1] + points[point3Index][1]) / 2 };
	double line3Middle[] = { (points[point3Index][0] + points[point2Index][0]) / 2,(points[point3Index][1] + points[point2Index][1]) / 2 };
	char line1Name[] = "a";
	char line2Name[] = "b";
	char line3Name[] = "c";
	GetLineByTwoPoints(points[point1Index],points[point2Index],line1);
	GetLineByTwoPoints(points[point1Index],points[point3Index],line2);
	GetLineByTwoPoints(points[point3Index],points[point2Index],line3);
	std::cout << "Medians" << std::endl;
	double median1[2];
	GetLineByTwoPoints(points[point1Index], line3Middle, median1);
	double median2[2];
	GetLineByTwoPoints(points[point2Index], line2Middle, median2);
	double median3[2];
	GetLineByTwoPoints(points[point3Index], line1Middle, median3);
	char median1Name[] = "median1";
	char median2Name[] = "median2";
	char median3Name[] = "median3";
	PrintLine(median1,median1Name);
	std::cout << std::endl;
	PrintLine(median2,median2Name);
	std::cout << std::endl;
	PrintLine(median3,median3Name);
	std::cout << std::endl;
	std::cout << "Heights" << std::endl;

	PrintThePerpendicularThroughAPoint(line3, points[point1Index], line3Name);
	PrintThePerpendicularThroughAPoint(line2, points[point2Index], line2Name);
	PrintThePerpendicularThroughAPoint(line1, points[point3Index], line3Name);
	std::cout << "Bisector" << std::endl;

	PrintThePerpendicularThroughAPoint(line3, line3Middle, line3Name);
	PrintThePerpendicularThroughAPoint(line2, line2Middle, line2Name);
	PrintThePerpendicularThroughAPoint(line1, line1Middle, line1Name);
}
void PrintEquationOfTangent(double a,double b,double c,double pointX) {
	double derivativeA = a * 2;
	double derivativeB = b;
	double functionalValueAtX = a * (pointX * pointX) + b * pointX + c;
	double functionalValueOfDerivativeAtX = derivativeA * pointX + derivativeB;
	double line[] = { functionalValueOfDerivativeAtX,functionalValueAtX - functionalValueOfDerivativeAtX*pointX };
	std::cout << "The tangent of the parabola is the ";
	char name[] = "";
	PrintLine(line,name);
	std::cout << std::endl;
}
void PrintTheIntersectionOfParabolaAndALine(double a, double b, double c, char lineName[], double lines[][2], char linesNames[][100], int linesCount) {
	int lineIndex = FindIndex(lineName, linesNames, linesCount);
	b -= lines[lineIndex][0];
	c -= lines[lineIndex][1];
	double D = b * b - 4 * a * c;
	if (D<0)
	{
		std::cout <<"No intersections"<<std::endl;
		return;
	}
	double x1 = (-b + sqrt(D)) / 2*a;
	double x2 = (-b - sqrt(D)) / 2*a;
	if (D>-Epsilon&&D<Epsilon)
	{
		std::cout << "There is one intersection in point("<<x1<<","<<GetValueOfALineAtAPoint(lines[lineIndex],x1)<<")" << std::endl;
	}
	else
	{
		std::cout << "There are two intersections in point(" << x1 << "," << GetValueOfALineAtAPoint(lines[lineIndex], x1) << ")"<<"and in point(" << x2 << "," << GetValueOfALineAtAPoint(lines[lineIndex], x2) << ")" << std::endl;
	}
}
void PrintSquareInfo(char lineName1[], char lineName2[], char lineName3[], char lineName4[], double lines[][2], char linesNames[][100], int linesCount) {
	int line1Index = FindIndex(lineName1, linesNames, linesCount);
	int line2Index = FindIndex(lineName2, linesNames, linesCount);
	int line3Index = FindIndex(lineName3, linesNames, linesCount);
	int line4Index = FindIndex(lineName4, linesNames, linesCount);

	double line1[2] = { lines[line1Index][0],lines[line1Index][1] };
	double line2[2] = { lines[line2Index][0],lines[line2Index][1] };
	double line3[2] = { lines[line3Index][0],lines[line3Index][1] };
	double line4[2] = { lines[line4Index][0],lines[line4Index][1] };
	if (line1[0]==line3[0])
	{
		if (line2[0]==line4[0])
		{
			double differance = (-1 / (line2[0])) - line1[0];
			if (differance>-Epsilon&&differance<Epsilon)
			{
				std::cout << "Rectangle" << std::endl;
			}
			else
			{
				std::cout << "Parallelogram" << std::endl;
			}
		}
		else
		{
			std::cout << "Trapezoid" << std::endl;
		}
	}
	else if(line2[0] == line4[0])
	{
		std::cout << "Trapezoid" << std::endl;
	}
	else
	{
		std::cout << "Quadrilateral" << std::endl;
	}
}
void PrintInstructions() {
	std::cout << "=================================================================================="<<std::endl;
	std::cout << "1: Print Lines" << std::endl;
	std::cout << "2: Print Points" << std::endl;
	std::cout << "L: Define Line (y= ax+b) (a,b,name)"<<std::endl;
	std::cout << "P: Define Point (x,y), (x,y,name)"<<std::endl;
	std::cout << "3: Is Point On The Line: (Line Name, Point Name)"<<std::endl;
	std::cout << "4: Get Parallel Line Of A Line In A Point: (Line Name, Point Name)"<<std::endl;
	std::cout << "5: Get Perpendicular Line Of A Line In A Point: (Line Name, Point Name)"<<std::endl;
	std::cout << "6: Get Intersection Of Two Lines: (First Line Name, Second Line Name)"<<std::endl;
	std::cout << "7: Get Triangle Info: (First Point Name, Second Point Name, Third Point Name)"<<std::endl;
	std::cout << "8: Get Tangent Of Parabola: (a, b, c, x)"<<std::endl;
	std::cout << "9: Get Intersection Of Parabola And A Line: (a, b, c, Line Name)" << std::endl;
	std::cout << "0: Get Rectangle Info: (First Point Name, Second Point Name, Third Point Name, Fourth Point Name)" << std::endl;
	std::cout << "C: Clear" << std::endl;
	std::cout << "X: Close"<<std::endl;
	std::cout << "==================================================================================" << std::endl;
}
int main()
{
	double points[100][2];
	double lines[100][2];
	char pointsNames[100][100];
	char linesNames[100][100];
	int currentPoint = 0;
	int currentLine = 0;
	char input = ' ';
	PrintInstructions();
	while (input!='X')
	{
		std::cin >> input;
		if (input=='1')
		{
			ListLines(lines, linesNames, currentLine);
		}
		else if (input == '2')
		{
			ListPoints(points, pointsNames, currentPoint);
		}
		else if (input == 'L')
		{
			double a;
			double b;
			char name[100];
			std::cin >> a >> b >> name;
			//Check for bugs names and zeros
			//fix string copy
			DefineLine(a, b, name, lines, linesNames, currentLine);
			currentLine++;
		}
		else if (input == 'P')
		{
			double a;
			double b;
			char name[100];
			std::cin >> a >> b >> name;
			//Check for bugs names
			DefinePoint(a, b, name, points, pointsNames, currentPoint);
			currentPoint++;
		}
		else if (input == '3')
		{
			char pointName[100];
			char lineName[100];
			std::cin >> lineName >> pointName;
			std::cout << (IsPointOnTheLine(pointName, lineName, points, lines, pointsNames, linesNames, currentPoint, currentLine) ? "Yes" : "No") << std::endl;
		}
		else if (input == '4')
		{
			char pointName[100];
			char lineName[100];
			std::cin >> lineName >> pointName;
			PrintTheParallel(pointName, lineName, points, lines, pointsNames, linesNames, currentPoint, currentLine);
		}
		else if (input == '5')
		{
			char pointName[100];
			char lineName[100];
			std::cin >> lineName >> pointName;
			PrintThePerpendicular(pointName, lineName, points, lines, pointsNames, linesNames, currentPoint, currentLine);
		}
		else if (input == '6')
		{
			char lineName1[100];
			char lineName2[100];
			std::cin >> lineName1 >> lineName2;
			PrintTheIntersection(lineName1, lineName2, lines, linesNames, currentLine);
		}
		else if (input == '7')
		{
			char point1Name[100];
			char point2Name[100];
			char point3Name[100];
			std::cin >> point1Name >> point2Name >> point3Name;
			PrintTriangleInfo(point1Name, point2Name, point3Name, points, pointsNames, currentPoint);
		}
		else if (input == '8')
		{
			double a = 0, b = 0, c = 0, pointX = 0;
			std::cin >> a, b, c, pointX;
			PrintEquationOfTangent(a, b, c, pointX);
		}
		else if (input == '9')
		{
			int a=0, b=0, c=0;
			char lineName[100];
			std::cin >> a, b, c, lineName;
			PrintTheIntersectionOfParabolaAndALine(a, b, c, lineName, lines, linesNames, currentLine);
		}
		else if (input == '0')
		{
			char line1Name[100];
			char line2Name[100];
			char line3Name[100];
			char line4Name[100];
			std::cin >> line1Name, line2Name, line3Name, line4Name;
			PrintSquareInfo(line1Name, line2Name, line3Name, line4Name, lines, linesNames, currentLine);
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
	/*char name[] = "afefsdf";
	char name1[] = "afefsdfsda";
	char name2[] = "afefsasddfsda";
	char name3[] = "new line";

	DefinePoint(1,5,name,points,pointsNames,currentPoint);
	currentPoint++;
	DefinePoint(4,-5,name1,points,pointsNames,currentPoint);
	currentPoint++;
	DefinePoint(-1, -2, name2, points, pointsNames, currentPoint);
	DefineLine(0,1,name,lines,linesNames,currentLine);
	currentLine++;
	DefineLine(1,1,name1,lines,linesNames,currentLine);
	currentPoint++;
	currentLine++;
	DefineLine(0, 5, name2, lines, linesNames, currentLine);
	currentLine++;
	DefineLine(1, 3, name3, lines, linesNames, currentLine);
	currentLine++;
	ListPoints(points,pointsNames,currentPoint);
	ListLines(lines,linesNames,currentLine);
	std::cout << IsPointOnTheLine(name,name,points,lines,pointsNames,linesNames,currentPoint,currentLine)<<std::endl;
	std::cout << GetValueOfALineAtAPoint(lines[0], 1.5) << std::endl;
	PrintTheParallel(name,name,points,lines,pointsNames,linesNames,currentPoint,currentLine);
	PrintThePerpendicular(name,name,points,lines,pointsNames,linesNames,currentPoint,currentLine);
	PrintTheIntersection(name1,name,lines,linesNames,currentLine);
	double line3[2];
	GetLineByTwoPoints(points[0],points[1],line3);
	PrintLine(line3,name3);
	std::cout << std::endl;
	PrintTriangleInfo(name, name1, name2,points,pointsNames,currentPoint);
	PrintEquationOfTangent(1,2,5,0);
	PrintTheIntersectionOfParabolaAndALine(1,2,5,lines[0]);
	PrintSquareInfo(lines[0], lines[1], lines[2], lines[3] );*/

}

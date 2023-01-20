#pragma once
#include <iostream>
bool DefinePoint(double a, double b, const char name[], double points[][2], char pointsNames[][MaxNameLength], int currentPoint);
void ListPoints(const double points[][2], const char pointsNames[][MaxNameLength], int currentPoint);
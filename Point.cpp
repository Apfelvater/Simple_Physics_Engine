#include <iostream>
#include "Point.h"

Point::Point(int intVal) : intValue(intVal) {}

void Point::setIntValue(int val) { intValue = val; }
int Point::getIntValue() { return intValue; }

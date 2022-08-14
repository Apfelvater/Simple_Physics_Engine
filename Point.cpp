#include <iostream>
#include "Point.h"

Point::Point() : intValue(-1) {}
Point::Point(int intVal) : intValue(intVal) {}

void Point::setIntValue(int val) { intValue = val; }
int Point::getIntValue() { return intValue; }
char Point::toChar() { return (char) intValue; }
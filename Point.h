#ifndef POINT_H
#define POINT_H

using namespace std;

class Point {
    private:
    int intValue;


    public:
    Point();
    Point(int intVal); 
    int getIntValue();
    void setIntValue(int val);
    char toChar();

};
#endif
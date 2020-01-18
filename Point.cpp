//
// Created by yuvallevy on 16/01/2020.
//

#include "Point.h"


int Point::getY() const {
    return y;
}

int Point::getX() const {
    return x;
}

Point::Point(int left,int right) : x(left), y(right) {}

const bool Point::operator==(const Point &otherPoint) const {
     return this->x == otherPoint.getX() && this->y == otherPoint.getY();
}

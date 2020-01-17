//
// Created by yuvallevy on 16/01/2020.
//

#include "Point.h"


int Point::getRight() const {
    return right;
}

int Point::getLeft() const {
    return left;
}

Point::Point(int right, int left) : right(right), left(left) {}

const bool Point::operator==(const Point &otherPoint) const {
     return this->left == otherPoint.getLeft() && this->right == otherPoint.getRight();
}

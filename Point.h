//
// Created by yuvallevy on 16/01/2020.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H
#pragma once

#include <string>

class Point {
private:
    int y;
    int x;
public:
    Point(int left, int right);


    int getY() const;

    int getX() const;

    const bool operator==(const Point &otherPoint) const;
};


#endif //EX4_POINT_H

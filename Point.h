//
// Created by yuvallevy on 16/01/2020.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H
#pragma once


class Point {
private:
    int right;
    int left;
public:
    Point(int left, int right);


    int getRight() const;

    int getLeft() const;

    const bool operator==(const Point &otherPoint) const;
};


#endif //EX4_POINT_H

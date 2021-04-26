//
// Created by zayna on 4/12/2021.
//

#ifndef CIRCLE_ASCIIREND_H
#define CIRCLE_ASCIIREND_H

#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <fstream>

using std::srand;
using std::rand;

struct coordinate {
    int x;
    int y;

    coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }

    coordinate(double x, double y) {
        this->x = x;
        this->y = y;
    }


    coordinate operator+(coordinate c1) {
        return {c1.x + x, c1.y + y};
    }
};

struct buffer {
private:
    char **data;
    int width;
    int height;
public:
    buffer(const int, const int);

    void plot(const int, const int, const char);

    void line(const coordinate, const coordinate);

    void circle(coordinate center, int radius);

    void randomstars(int amountofstars);

    void bird(coordinate coor);

//    void circle2(coordinate center, int radius);
    void tree(int x, int y);

    void mountain(int x, int y);

    void bike(int x, int y);

    void lamp(int x, int y);

    void lightoflamp(int x, int y);

    void draw(std::ostream &out);

    void clear();

    ~buffer();
};

#endif //CIRCLE_ASCIIREND_H

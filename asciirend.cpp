//
// Created by zayna on 4/18/2021.
//

#include "asciirend.h"

buffer::buffer(const int W, const int H) {
    this->width = W;
    this->height = H;

    this->data = new char *[H];
    for (int i = 0; i < H; ++i)
        this->data[i] = new char[W];

    clear();
}

void buffer::plot(const int x, const int y, const char c) {
    data[y][x] = c;
}

void buffer::line(const coordinate start, const coordinate end) {
    int deltax = end.x - start.x;
    int deltay = end.y - start.y;
    double delta_error = (double) deltay / deltax;
    if (delta_error < 0) delta_error = -delta_error;
    double error = 0;
    int y = start.y;
    for (int x = start.x; x <= end.x; ++x) {
        plot(x, y, '=');
        error += delta_error;
        if (error >= 0.5) {
            if (deltay > 0) ++y;
            else --y;
            --error;
        }
    }
}

void buffer::circle(coordinate center, int radius) {
    for (int i = 0; i <= center.x + radius and i < width; i++) {
        for (int j = 0; j <= center.y + radius and j < height; j++) {
            if (abs((i - center.x) * (i - center.x) + (j - center.y) * (j - center.y) - (radius * radius)) < 3) {
                plot(i, j, '*');
            }
        }
    }
}

//void buffer::circle(coordinate center, int radius) { //I used Midpoint circle algorithm
//    int f = 1 - radius;
//    int ddF_x = 0;
//    int ddF_y = -2 * radius;
//    int x = 0;
//    int y = radius;
//    plot(center.x, center.y + radius, '*');
//    plot(center.x, center.y - radius, '*');   //basic 4 points
//    plot(center.x + radius, center.y, '*');
//    plot(center.x - radius, center.y, '*');
//
//    while (x < y) {
//        if (f >= 0) {
//            y--;
//            ddF_y += 2;
//            f += ddF_y;
//        }
//        x++;
//        ddF_x += 2;
//        f += ddF_x + 1;
//        plot(center.x + x, center.y + y, '*');
//        plot(center.x - x, center.y + y, '*');
//        plot(center.x + x, center.y - y, '*');
//        plot(center.x - x, center.y - y, '*');
//        plot(center.x + y, center.y + x, '*');
//        plot(center.x - y, center.y + x, '*');
//        plot(center.x + y, center.y - x, '*');
//        plot(center.x - y, center.y - x, '*');
//    }
//}
void buffer::bird(coordinate coor) {
    plot(coor.x + 2, coor.y - 2, '=');
    plot(coor.x - 1, coor.y - 1, '=');
    plot(coor.x - 2, coor.y - 2, '=');
    plot(coor.x - 6, coor.y, '=');
    plot(coor.x - 4, coor.y - 1, '=');
    plot(coor.x + 4, coor.y - 1, '=');
    plot(coor.x + 6, coor.y, '=');
}

void buffer::bike(int x, int y) {
    //center (20,38)
    line({x - 10, y}, {x, y});
    line({x - 5, y - 3}, {x + 6, y - 3});
    line({x - 10, y}, {x - 5, y - 3});
    line({x, y}, {x + 5, y - 3});
    line({x + 10, y}, {x, y - 6});
    line({x - 5, y - 3}, {x - 5, y - 4});
    line({x - 8, y - 4}, {x - 3, y - 4});
    line({x - 3, y - 6}, {x, y - 6});
    line({x + 5, y - 6}, {x + 7, y - 6});
    line({x, y - 6}, {x + 2, y - 3});
    line({x + 1, y - 6}, {x + 2, y - 3});
    //wheel
    circle({x - 10, y}, 3);
    circle({x + 10, y}, 3);
}

void buffer::mountain(int x, int y) {

    line({x, y}, {width / 4, height / 4});
    line({(width / 4) + 1, (height / 4) + 1}, {width / 2, y});
    line({((width / 8) * 3) + 14, ((height / 4) * 3) + 1}, {(width / 4) * 3, height / 2});
    line({((width / 4) * 3) + 1, (height / 2) + 1}, {width, y});
}

void buffer::lamp(int x, int y) {
    plot(x, y - 16, '*');
    for (int i; i < 11; i++) {
        plot(x, y - i, '=');
    }
    circle({x, y - 13}, 2);
}

void buffer::randomstars(int amountofstars) {
//x = MAX + rand() % (MAX-MIN + 1)
    for (int j = 0; j < amountofstars; j++) {
        int x = rand() % width;
        int y = rand() % height;
        if (data[y][x] == ' ') {
            plot(x, y, '*');
        }
    }

}

void buffer::lightoflamp(int x, int y) { //same as lamp
    plot(x + 3, y - 13 + 2, '\\');
    plot(x - 3, y - 13 + 2, '/');
    plot(x - 3, y - 13 - 2, '\\');
    plot(x + 3, y - 13 - 2, '/');
    plot(x + 3, y - 13, '-');
    plot(x - 3, y - 13, '-');
}

void buffer::tree(int x, int y) {
    plot(x, y, '=');
    plot(x, y - 1, '=');
    plot(x, y - 2, '=');
    plot(x, y - 3, '=');
    plot(x - 1, y - 5, '=');
    plot(x - 4, y - 3, '=');
    plot(x - 3, y - 4, '=');
    plot(x - 1, y - 8, '=');
    plot(x - 4, y - 6, '=');
    plot(x - 3, y - 7, '=');
    plot(x - 1, y - 11, '=');
    plot(x - 4, y - 9, '=');
    plot(x - 3, y - 10, '=');
    plot(x - 1, y - 14, '=');
    plot(x - 4, y - 12, '=');
    plot(x - 3, y - 13, '=');
    line({x, y - 6}, {x + 4, y - 3});
    line({x, y - 9}, {x + 4, y - 6});
    line({x, y - 12}, {x + 4, y - 9});
    line({x, y - 15}, {x + 4, y - 12});

}

void buffer::draw(std::ostream &out) {

    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            out << this->data[i][j];
        }
        out << "\n";
    }
    out << std::endl;//сбрасывает буффер вывода(дольще)
}

buffer::~buffer() {
    for (int i = 0; i < this->height; ++i)
        delete[] this->data[i];
    delete[] this->data;
}

void buffer::clear() {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->data[i][j] = ' ';
        }
    }
}

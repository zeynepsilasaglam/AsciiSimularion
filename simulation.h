//
// Created by zayna on 4/18/2021.
//


#ifndef CIRCLE_SIMULATION_H
#define CIRCLE_SIMULATION_H
//also can be named as engine
#include "asciirend.h"
#include <iostream>
#include "math.h"
#include <conio.h>


namespace simulation {
    coordinate get_vector_by_angle(int radius, double angle);

//coordinate get_point_by_angle(coordinate c,double angle);
    void speed();

    void day();

    void night();
}
#endif //CIRCLE_SIMULATION_H

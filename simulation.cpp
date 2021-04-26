//
// Created by zayna on 4/18/2021.
//
#include "simulation.h"
//also can be named as engine
#define PI 3.14
#define height 44
#define width 189
double SPEED_OF_SIMULATION;

coordinate simulation::get_vector_by_angle(int radius, double angle) {//radius=lenghtof vector
    angle = ((int) angle % 360 - 180) * PI / 180; //to turn it into degrees
    return {cos(angle) * radius, sin(angle) * radius};
}

//coordinate get_point_by_angle(coordinate c,double angle) {//radius=lenghtof vector
//    angle = ((int) angle % 360 - 180) * PI / 180; //to turn it into degrees
//    return {c.x*cos(angle), c.y*sin(angle)};
//}
void simulation::speed() {
    std::string speed;
    std::cout << "choose the speed of the simulation:\n";
    std::cout << "\tslow\n\tfast\n";
    std::cin >> speed;
    if (speed == "slow" || speed == "fast") {
        std::ifstream myfile;
        myfile.open(speed + ".txt");
        double speed2;
        myfile >> speed2;
        SPEED_OF_SIMULATION = speed2; //taking some parameters from file
        myfile.close();
    }
}

void simulation::day() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    buffer screen(width, height);
    screen.clear();
    for (int i = 0; i < 120; i++) {
        //sun
        screen.circle(get_vector_by_angle(40, i * 2) + coordinate(94, 44), 4);

        //road
        screen.line({0, 42}, {189, 42});
        //bike
        screen.bike(20 + i, 38);
        screen.tree(140 - i, 41);
        if (i % 4 == 0) {
            screen.bird({184 - i, 28});
        }
        screen.draw(std::cout);
        if (kbhit()) {
            char ch = getch();
            switch (ch) {
                case 'p':
                    std::ofstream myfile;
                    myfile.open("screenshot.txt");
                    screen.draw(myfile);
                    myfile.close();

            }
        }
        screen.clear();
        sleep(SPEED_OF_SIMULATION);
        system("cls");
    }
}

void simulation::night() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);//ускоряет ввод вывод
    buffer screen(width, height);
    screen.clear();
    for (int i = 0; i < 120; i++) {

        //moon
        screen.circle(get_vector_by_angle(5, i * 7) + coordinate(160, 12), 4);
        //road
        screen.line({0, 42}, {width, 42});
        //mountain
        screen.mountain(0, 41);
        //bike
        screen.bike(20 + i, 38);
        //lamp
        screen.lamp(140 - i, 41);
        if (i % 4 == 0) {
            screen.lightoflamp(140 - i, 41);
            screen.randomstars(30);
        }
        screen.draw(std::cout);
        if (kbhit()) {
            char ch = getch();
            switch (ch) {
                case 'p':
                    std::ofstream myfile;
                    myfile.open("screenshot.txt");
                    screen.draw(myfile);
                    myfile.close();

            }
        }
        screen.clear();
        sleep(SPEED_OF_SIMULATION);
        system("cls");
    }
}



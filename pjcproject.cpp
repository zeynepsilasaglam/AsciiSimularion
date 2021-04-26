#include <iostream>
#include "simulation.h"

int main() {
    char mode;
    std::cout << "Welcome!\n";
    simulation::speed();
    std::cout << "choose the mode of the simulation(print 1 or 2):\n";
    std::cout << "\t1-day\n\t2-night\n";
    std::cout << "P.S press <p> to take a screenshot\n\n";
    std::cin >> mode;
    switch (mode) {
        case '2':
            simulation::night();
            break;
        case '1':
            simulation::day();
            break;
    }

}
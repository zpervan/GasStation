#include "Code/Library/gas_station.h"
#include "Code/Library/constants.h"

#include <iostream>

int main() {
    // Even though std::endl is considered a bad programming practice due to slow-downs,
    // but let's flush the data to the console, so we have an overview of the simulation.
    std::cout << "Welcome to Zvonimir's gas station!" << std::endl;

    GasStation gasStation{Constants::GAS_PUMPS_COUNT, Constants::CARS_COUNT};
    gasStation.simulate();

    return EXIT_SUCCESS;
}
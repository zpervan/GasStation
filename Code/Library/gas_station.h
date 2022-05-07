#pragma once

#include "car.h"
#include "gas_pump.h"

#include <queue>
#include <thread>
#include <vector>
#include <memory>

/// @brief Contains all the creation and simulation logic for the gas station.
class GasStation
{
public:
    // RAII
    GasStation(std::size_t numberOfGasPumps, std::size_t numberOfCars);
    GasStation() = delete;
    GasStation(const GasStation & gasStation) = delete;
    GasStation(GasStation && gasStation) = delete;
    GasStation operator=(const GasStation & gasStation) = delete;
    GasStation& operator=(GasStation && gasStation) = delete;

    /// @brief Entry point which runs the gas station simulation.
    void simulate();

    /// @brief Checks whether the car is next in line an can fill up.
    /// @param carId Car ID
    /// @return @c true if it's next in line and can fill up, @c false otherwise
    bool canFillUp(std::size_t carId);

    /// @brief Puts the car back in the queue (line).
    /// @param carId Car ID
    void addCarToLine(std::size_t carId);

    /// @brief Removes the front car from thr queue (line).
    void removeCarFromQueue();

    // Getters
    std::vector<std::unique_ptr<GasPump>>& getGasPumps();

private:
    void createGasPumps(std::size_t numberOfGasPumps);
    void createCars(std::size_t numberOfCars);
    void printStatistics();

    std::vector<std::thread> mThreads;
    std::vector<std::unique_ptr<GasPump>> mGasPumps;
    std::vector<Car> mCars;
    std::queue<std::size_t> mCarQueue;
};
